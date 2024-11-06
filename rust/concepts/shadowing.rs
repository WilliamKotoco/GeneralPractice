fn main()
{
    let x = 5;

    let x = x + 1;

    {
        let x = x*2;
        println!("Scope inside {x}");
    }
    println!("Scope outside {x}");


    // we can even use different data types as shadowing
    let word = "   ";
    let word = word.len();

    println!("{word}");
}
