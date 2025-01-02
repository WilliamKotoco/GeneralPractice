
use std::io;
// this program intends to show how to safely access a position in a vector
fn main() {
    let v = vec![true, true, true];

    loop {
        let mut input_text = String::new();
        io::stdin()
            .read_line(&mut input_text)
            .expect("failed to read from stdin");

        let trimmed = input_text.trim();


        let index: usize = match trimmed.parse::<usize>() {
            Ok(i) => i,
            Err(_) => {
                println!("Input is not a valid integer: {}", trimmed);
                continue; // volta ao início do loop
            }
        };


       match v.get(index) {
        
            Some(result) => println!("Bullet"),
            None => println!("Not a valid position in the revolver"),
        }
    }
}
