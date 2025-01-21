struct Point<T>{
    x: T,
    y: T,

}

struct Ponint2<T,U>{
    x: T,
    y: U
}


// even when Point is generic
// we can implement methods only on f32 instances for example
impl Point<f32>{
    fn sum(&self) -> f32{
        (self.x + self.y)
    }
}

fn main()
{
    let point = Point{x: 5, y: 3};

    let point2 = Point{x: 3.3, y: 4.4};

    // cannot use different types
    // let invalid = Point{x: 3, y: 4.4}


    let point3 = Ponint2{x: 3, y: 4.4};
}


// A result can have some value and can have some error
enum Result<T,E>
{
    Ok(T),
    Err(E),
}