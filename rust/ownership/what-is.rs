// Ownership ditates how rust deals with memory allocation on heap.
// Ownership rules:
// 1 - Each value in Rust has an owner
// 2 - There can be only one owner at the time
// 3 - When the owner goes out the scoupe, the value will be dropped

/// When the variable the owns the memory space goes out of scope, the memory is automatically returned
/// It is done by a rust function called drop, done automatically

fn main()
{
    {
        let s =String::from("Hello world");
        // s is valid here
    }
    // s is no longer valid, so it will cause an error
//    println!("{s}");


    string_copy();
    function_ownership();
}


fn string_copy()
{
    // for heap allocations, rust does not copy the content. It creates another reference to the heap memory
    // i
    let s1 = String::from("Hello world");
    let s2 = s1;

    println!("{s2}");

    // this line will cause error. Once we create another stack pointer to a heap, the rust will eliminate the original one.
    // This happens to avoid double free errors.
    //
    // so it is not shallow nor deep copy, it is literally a move
    //println!("{s1}");

    let s3 = String::from("Test Deep Copy");
    let s4 = s3.clone();

    println!("{s3}");
    println!("{s4}");
}


fn function_ownership()
{
    let s = String::from("Hello");

    println!("{s}");

    hello_fn(s);

    // this line will cause an error. Passing heap values into functions is a move and not a copy
    // so rust will call drop once you're out the function scope
    
  // println!("Outside hello function: {s}");


    // this does not happen to variables allocated on stack. They are copied.
  let x = 3;

  println!("Integer before function call: {x}");
  int_fn(3);
  println!("Integer after function call: {x}");


}

fn hello_fn(s : String)
{
    println!("Inside hello function: {s}");

}


// pass mut in argument to be able to change the value
fn int_fn(mut integer : i32){
     println!("IN FUNCTION: {integer}");

    integer = integer + 3;
     println!("IN FUNCTION: Changed integer: {integer}");
}