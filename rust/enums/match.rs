use std::io;

enum Coin{
    Dolar,
    Euro,
    Real,
    Iene,
    Invalid,
}

fn main()
{
    println!("Input the amount of money em reais");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let amount : f32 = input.trim().parse().expect("Pleae enter a valid number");
    
    println!("Input the desired currency: ");
    println!("[1] For dollar");
    println!("[2] For Euro");
    println!("[3] For Real");
    println!("[4] For Iene");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let coin : i32 = input.trim().parse().expect("Please enter a valid number");

    let currency = get_currency(coin);

    let total_amount = convert(currency, amount);

    println!("Money: {total_amount}");
}

fn get_currency(input: i32) -> Coin{

    // in match, the arms must cover all possibilites.
    // The Coin::Invalid is necessary to cover all possibilities. It is not possible to handle only 1 to 4 in i32
    //: we must exhaust every last possibility in order for the code to be valid. 
    match input{
        1 => Coin::Dolar,
        2 => Coin::Euro,
        3 => Coin::Real,
        4 => Coin::Iene,
            _ => Coin::Invalid, // _ meant that we want to ignore. If it is useful to store the input, we must use the key "other".
    }
}

fn convert(currency: Coin, amount: f32) -> f32{
    match currency{
        Coin::Dolar => (amount/6.0) ,
        Coin::Euro => (amount/6.36) ,
        Coin::Real => amount ,
        Coin::Iene => amount * 4.0,
        Coin::Invalid => {
            println!("The chosen currency was invalid!");
            amount

        }
    }
}