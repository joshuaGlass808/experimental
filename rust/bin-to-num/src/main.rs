fn main() {
    bin_to_u8("1011".to_string());
    bin_to_u8("0011".to_string());
    bin_to_u8("0001".to_string());
    bin_to_u8("1001".to_string());
    bin_to_u8("0000".to_string());
}

// small binary string -> unsigned 8bit integer.
// obviously you gotta keep it small and this is 
// just to have fun learning some rust.
fn bin_to_u8(bin_str: String) -> u8 {
    let mut total: u8 = 0;
    let length: u8 = bin_str.len() as u8;
    
    for (i, c) in bin_str.chars().enumerate() {
        let power: u8 = length - (i as u8) - 1;
        total += if c == '1' { u8::pow(2, power as u32) } else { 0 };
    }

    return total;
}
