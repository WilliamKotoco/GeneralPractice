
fn main() {

    // error due to changing immutable variable
    /* 
    let x = 5;
    println!("value is {x}");

    x = 6;
    println!("value is {x}");
    */

    let mut x = 5;
    println!("Value is {x}");
    x = 6;
    println!("Value is {x} now");

    // constant are always immutable, and they need to have the annotaded data type
    const PI_NUMBER: f32 = 3.141234342412;

    println!("Value of constant pi is {PI_NUMBER}");
}
