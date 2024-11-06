/// obtain user input  
use std::io;
use rand::Rng;

use std::cmp::Ordering;

 fn main() {
    
   // defines a rng function local to the current thread  
    let secret = rand::thread_rng().gen_range(1..=100);
    
    // looop keyword creates an infinite loop
    loop {
        


    // in rust variables are immutable by defaut. Once we give them a value 
    //  it won't change. We must explicity state it is mutable 
    let mut guess = String::new(); // String is a type and new is a function associated with the
                                   // string type  
    // also it is necessary to move the redefinition of the string inside the loop 
    // because it accumulates the value from the previous try

        println!("Input ur guess:");   
    io::stdin().read_line(&mut guess).expect("Failed to read line");
    // we shadow the the previous value of guess to a new one 
    // .trim() -> eliminate whitespace or newline 
    // .parse() -> converts string to another type. Using : after guess tell Rust the exact number
    // type we want 
    let guess : u32 = match guess.trim().parse() {
        Ok(num) => num,

        Err(_) => continue,
    };
    
    println!("You guessed {}", guess);
    println!("The secret number was {}", secret);
   
    // guess .cmp uses the method compare in the guess variable passin the secret as the input 
    match guess.cmp(&secret){
        Ordering::Less => println!("Small!"),
        Ordering::Greater => println!("Greater"),
        Ordering::Equal => {
            println!("You win!");
            break;
        }
    }
    }


}
