

fn main()
{
    let mut s = String::from("Hello");

    println!("S before function: {s}");

    // by passing by reference we do not transfer the ownership.
    use_string(&s);

    println!("S after function: {s}");


    let mut_s = &mut s;

    // this line will cause error. We cannot have two 
    // mutable references for the same string IN THE SAME SCOPE.
    //
    // this is avoids data races.
    
//    let mut_s2 = &mut s;


    // we also cannot have a immutable reference in the same scope
    // of a variable that haves the same reference but mutable.
    // r cannot  expect s to change, and by doing that we allow r to have a little surprise if mut_s decides to change
    // the value of s.
    
    // let r = &s;
  
  
    modify_string(mut_s);

}

//  Here we are receiveing a reference of a heap memory. We do not take ownership in this case.
fn use_string(s : &String)
{

    println!("S inside function: {s}");

    // this line will cause error. References are not mutable by default.
   // s.push_str("Test");
}

fn modify_string(s : &mut String)
{
    s.push_str(" test");

    println!("Modified string: {s}");



}