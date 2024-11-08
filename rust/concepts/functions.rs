use std::string; 
fn main(){
    println!("Main function \n");
    
    another_hello(32, String::from("Haru"));

    let value = expression();
    println!("Value of the expression is {value}");

    println!("Value plus one is {0}", sum_one(value));

}

fn another_hello(x: i32, name: String)
{
    println!("Hello {name}");
    println!("The number is {x}");
}

fn expression() -> i32{
    let y = 
    {
        let x = 3;
        x + 4 // the expression inside the scope will be assigned to y
    };

    y // evaluate y (in other words, return it) 

    // we use semi colon only in stsatements, not in expressions. 
    // adding a semicolon will cause error
}

fn sum_one(x : i32) -> i32
{
    x + 1 // not semicolun because we are evaluating
}