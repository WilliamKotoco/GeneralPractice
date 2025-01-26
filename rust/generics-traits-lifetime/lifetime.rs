// lifetimes are the scope for which a reference is valid. The aim is
// to prevent dangling references (reference data other than it is intended
// https://youtu.be/juIINGuZyBc?si=ifOYlsPAY9Yg9aqA


// the function below will not work because it retuns a reference to either x
// or y. However, we do not know the lifetime of x and y, impossible to do borrow checker.
// this function can be called for different variables with different lifetimes.
fn longest(x: &str, y: &str) -> &str{
    if x.len() > y.len()
    {
        x
    }
    else{
        y
    }
}

// first we create a lifetime called a

/// now the result will have the smalest lifetime of its arguments (either x or y in this case)
fn correct_longest<'a>(x: &'a str, y: &'a str) ->  & 'a str{
 unimplemented!();
}


fn main()
{
    let string1 = String::from("Abc");

    let result;
    {
            let string2 = String::from("ab");
            result = longest(string1.as_str(), string2.as_str());
    }

    // error because result will have the smalest lifetime from the function
    // which is the string 2.
    println!("{}", result);
}