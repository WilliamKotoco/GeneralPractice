// using for errors that must be recoverable
// you use the result enum, which consists of Ok(T) and Err(E)
// T and E being generic types
//

use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let file_result = File::open("teste.txt");

    let file_handler = match file_result {
        Ok(file) => file,
        Err(error) => panic!("Not possible to open the file: {:?}", error),
    };

    // the matching from line 12 to 15 can be summarized as:
    let file = File::open("cu.txt").unwrap();

    // use .expected("error message") to customize the error message.

    let file_result = File::open("hello.txt");

    // handles the error in opening due non existence
    let file_handler = match file_result {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(file_created) => file_created,
                Err(e) => panic!("Impossible to create file"),
            },

            other_error => panic!("Other error"),
        },
    };

    println!("File created");
}
