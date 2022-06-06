package main

import (
  "fmt"
  "github.com/joshuaGlass808/experimental/go/scanner/scanner"
  "os"
  "path/filepath"
  "sync"
)

// I can't decide if I want to use panic or log.Fatal on errs.. help me decide.
// I tried to make sure everything returns the data, err.
func main() {
  // Get things setup and started.
  pi_scanner, setup_err := scanner.ScannerSetup("/var/sqlite/scans.db")
  if setup_err != nil {
    panic(setup_err)
  }
  fmt.Println("scanner was successfully setup and created")
  devices, find_dev_err := FindDevices()
  if find_dev_err != nil {
    panic(find_dev_err)
  
  var wg sync.WaitGroup
  for _, file_path := range devices {
    fmt.Println("starting go routine")
    wg.Add(1)
    go pi_scanner.ReadDevice(file_path, &wg)
  }
  wg.Wait()
}

func FindDevices() ([]string, error) {
  files_list := []string{}
  var err error = nil
  regex_pattern := "/dev/hidraw*"
  walk_err := filepath.Walk("/dev/", func(path string, _ os.FileInfo, err error) error {
    files_list = append(files_list, path)
    return err
  })
  if walk_err == nil {
    tmp_list := []string{}
    for _, path := range files_list {
      bool_match, _ := filepath.Match(regex_pattern, path)
      if bool_match {
	tmp_list = append(tmp_list, path)
      }
    }
    files_list = tmp_list
  } else {
    err = walk_err
  }
  return files_list, err
}
