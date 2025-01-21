use std::fs::File;
use std::io::{self, Read};

fn main() {

    match username_from_file(){
        Ok(username) => println!("Hello, {}!", username),
        Err(e) => println!("Error reading file: {}", e),  // this line will only be executed if the username_from_file function returns an Err value
    }

}


fn username_from_file() -> Result<String, io::Error>{

    /// the ? operator:
    /// if ok returns value to expression
    /// if Err it will return the error from the entire function
    /// the ? operator will also convert the error to the one expected
    /// in the return value
    
    ///  let mut username_file = match username_file_result {
    ///    let mut username_file = match username_file_result {
    ///        Ok(file) => file,
    ///       Err(e) => return Err(e),
    ///  }
    
    let mut username_file = File::open("hello.txt")?;

    let mut username = String::new();

    username_file.read_to_string(&mut username)?;

    Ok(username)
}