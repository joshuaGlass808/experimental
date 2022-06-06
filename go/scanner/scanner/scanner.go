package scanner

import (
  "bufio"
  "database/sql"
  "fmt"
  _ "github.com/mattn/go-sqlite3"
  "os"
  "regexp"
  s "strings"
  "sync"
  "time"
)

// To build run:
// env CC=arm-linux-gnueabi-gcc GOOS=linux GOARCH=arm GOARM=6 CGO_ENABLED=1 go build -o arm_lane_scanner -v
// need to build from the dir it exists in.
// I can't decide if I want to use panic or log.Fatal on errs.. help me decide.
// I tried to make sure everything returns the data, err.

var c_hid_lower = map[int]rune{4: 'a', 5: 'b', 6: 'c', 7: 'd', 8: 'e', 9: 'f', 10: 'g', 11: 'h', 12: 'i', 13: 'j', 14: 'k', 15: 'l', 16: 'm', 17: 'n', 18: 'o', 19: 'p', 20: 'q', 21: 'r', 22: 's', 23: 't', 24: 'u', 25: 'v', 26: 'w', 27: 'x', 28: 'y', 29: 'z', 30: '1', 31: '2', 32: '3', 33: '4', 34: '5', 35: '6', 36: '7', 37: '8', 38: '9', 39: '0', 44: ' ', 45: '-', 46: '=', 47: '[', 48: ']', 49: '\\', 51: ';', 52: '\'', 53: '~', 54: ',', 55: '.', 56: '/'}
var c_hid_upper = map[int]rune{4: 'A', 5: 'B', 6: 'C', 7: 'D', 8: 'E', 9: 'F', 10: 'G', 11: 'H', 12: 'I', 13: 'J', 14: 'K', 15: 'L', 16: 'M', 17: 'N', 18: 'O', 19: 'P', 20: 'Q', 21: 'R', 22: 'S', 23: 'T', 24: 'U', 25: 'V', 26: 'W', 27: 'X', 28: 'Y', 29: 'Z', 30: '!', 31: '@', 32: '#', 33: '$', 34: '%', 35: '^', 36: '&', 37: '*', 38: '(', 39: ')', 44: ' ', 45: '_', 46: '+', 47: '{', 48: '}', 49: '|', 51: ':', 52: '"', 53: '~', 54: '<', 55: '>', 56: '?'}

type PiScanner struct {
  HidMaps struct {
    upper map[int]rune
    lower map[int]rune
  }
  DB_connection struct {
    connection   *sql.DB
    db_file_path string
  }
}

func (scanner PiScanner) BarcodeAlreadyScanned(barcode string) (int, error) {
  var (
    err error = nil
    count int
  )
  sql_err := scanner.DB_connection.connection.QueryRow("select count(*) from scans where barcode=$1", barcode).Scan(&count)
  err = sql_err

  return count, err
}

func (scanner PiScanner) UpdateScan(scan string, scanner_id string) (sql.Result, error) {
  date := time.Now().Format("2006-01-02 15:04:05")
  res, err := scanner.DB_connection.connection.Exec("insert into scans (scanner_id, barcode, is_uploaded, scanned_at) values($1, $2, $3, $4)", scanner_id, scan, 0, date)
  return res, err
}

func (scanner PiScanner) IsDBConnected() bool {
  if scanner.DB_connection.connection != nil {
    return true
  }
  return false
}

// Not sure what this should return if anything at all.
func (scanner PiScanner) ReadDevice(dev_path string, wg *sync.WaitGroup) {
  var (
    ss      string
    shift   bool = false
    is_done bool = false
  )
  fp, file_err := os.Open(dev_path)
  // File successfully opened.
  if fp != nil {
    fmt.Println("Starting forever loop")
    r := bufio.NewReader(fp)
    for true {
      for is_done != true {
	char, _, err := r.ReadRune()
	if err != nil {
	//
          fmt.Println(err)
	}
	if true {
	  if int(rune(char)) > 0 {
	    // 40 is carriage return which lets us know we are done looking.
	    if int(rune(char)) == 40 {
	      is_done = true
	      break
	    }
	    if shift {
	      // use HidMaps.upper
	      // If it is a '2' then it is the shift key
	      // If not a 2 then lookup the mapping
	      if int(rune(char)) == 2 {
	        shift = true
	      } else {
	        ss += string(scanner.HidMaps.upper[int(rune(char))])
		shift = false
	      }
	    } else {
	      // use HidMaps.lower
	      // If it is a '2' then it is the shift key
	      // If not a 2 then lookup the mapping
	      if int(rune(char)) == 2 {
	        shift = true
	      } else {
		ss += string(scanner.HidMaps.lower[int(rune(char))])
		shift = false
	      }
	    }
	  }
	}
      }
      if len(ss) > 9 {
        var string_ss string = string(ss)
        // Some scanners may still have an ID assigned,
	// so below is here just in case: ID was separated with a ;
	if s.Contains(string_ss, ";") {
	  string_ss = s.Split(string_ss, ";")[1]
	}
	match, _ := regexp.MatchString("[a-z]+", string_ss)
	if (len(string_ss) == 18 && s.Contains(string_ss, "1Z")) ||
	  (len(string_ss[len(string_ss)-12:]) == 12 && !match && string_ss[0:3] != "420") ||
	  (len(string_ss) == 15 && string(string_ss[0]) == "D") {
	  if !s.Contains(string_ss, `1Z`) || string(string_ss[0]) == `D` {
	    string_ss = string_ss[len(string_ss)-12:]
	  }
	  //send ss to the db updater.
	  scanned_count, check_err :=scanner.BarcodeAlreadyScanned(string_ss)
	  if check_err != nil {
	    fmt.Println(check_err)
	  }
	  if scanned_count == 0 {
	    res, errt := scanner.UpdateScan(string_ss, "1")
	    fmt.Println("Results: ", res)
	    fmt.Println("Error: ", errt)
	  }
	  is_done = false
	  ss = ""
	}
      }
    }
  } else {
    // I think something caused a change in
    // the file path while the program was running.
    // Not 100% sure though.

    // Update - Pretty sure the error was actually thrown by the ReadRune() method
    // in the bufio lib.
    fmt.Println(file_err)
  }
}

// DB_PATH - path for SQLite file.
func ScannerSetup(db_path string) (*PiScanner, error) {
  var err error = nil
  scanner := &PiScanner{}
  scanner.HidMaps.upper = c_hid_upper
  scanner.HidMaps.lower = c_hid_lower
  // Checking to make sure sqlite file exists.
  _, file_err := os.Stat(db_path)
  if !os.IsNotExist(err) {
    // path/to/file exists
    scanner.DB_connection.db_file_path = db_path
    db, sql_err := sql.Open("sqlite3", scanner.DB_connection.db_file_path)
    if sql_err != nil {
      err = sql_err
      return scanner, err
    }
    scanner.DB_connection.connection = db
  } else {
    err = file_err
  }

  return scanner, err
}
