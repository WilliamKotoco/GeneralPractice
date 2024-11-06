fn main() {
    // the rust compiler always try to guess the type 
    // it gives compiler errors if it cannot infer the type 

    let num1 : i64;  // integer of 64 bits
    
    let num2 : u64; // unsigned of 64 bits 
                    //
    let num3 = 98_222;

    println!("{num3}");


    // compound types
    let tuple: (i32, f64, u8) = (10, 100.55, 9);
    
    let (x, y, z) = tuple;
    println!("Middle value from tuple: {y}");

    // it is also possible to acess like a struct
    println!("Value of index 3 {0}", tuple.2    );
}


