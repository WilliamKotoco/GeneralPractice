use std::io;

fn main()
{
    let  young = age();

    println!("He is young ? {young}"); 

    // each arm of the if must have compatible types
    let price = if young {10} else {30};

    println!("The price of the theater is {price}");

    let counter = return_counter();

    println!("Last value of counter is {counter}");


    nestered_loops();

    loop_while();

    for_loop();
}

fn age() -> bool
{
    let mut age = String::new();

    io::stdin().read_line(&mut age).expect("Failed reading");

    let age : i32 = match age.trim().parse(){
        Ok(num) => num,
        Err(_) => {
            println!("Error parsing");
           return false; 
        } 
    };

    age < 18
}

fn return_counter() -> i32 {
    let mut counter  = 0;

    let result = loop{
        println!("{counter}");
        
        counter += 1;

        if  counter % 10 == 0{
            break counter
            // you could use return counter to exit the function 
        }
    };

    counter 
}

fn nestered_loops()
{
    let mut count = 0;

    // labeling the loop to be able to break from it
    'counting_up: loop{
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("Remaining = {remaining}");
            if remaining == 9
            {
                break;
            }

            if count == 2{
                break 'counting_up; // break the external loop within the interal loop.
            }
            remaining -= 1; 
        }

        count += 1;
    }
}

fn loop_while()
{
    let mut number = 10;
    while number > 0 {
        println!("Number is {number}");
        number -= 1;
    }
}

fn for_loop()
{
    let a = [10,20,30,50,60];

    for element in a {
        println!("Element is: {element}");
    }
}