/// create a struct to represent numbers 
/// from 0 to 100 and validate new numbers
/// to be valid in that range
/// 
/// 
struct SpecialNumber{
    number: u32,
}

impl SpecialNumber{

    fn new(number: u32) -> SpecialNumber{
        if number < 1  || number > 100 {
            panic!("Number must be between 1 and 100");
        }

        SpecialNumber{number}
    }

    fn get_number(&self) -> u32 {
        self.number
}
}


fn main(){
    let number = SpecialNumber::new(50);
    println!("The number is {}", number.get_number());


    let invalid_numer = SpecialNumber::new(102);;
}