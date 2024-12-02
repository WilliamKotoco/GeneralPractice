struct Point(f32, f32, f32);

fn main() {
    let point1 = Point(10.0, 20.0, 30.0);
    let point2 = Point(40.0, 50.0, 60.0);

    let sum = (point2.0 - point1.0).powi(2)
        + (point2.1 - point1.1).powi(2)
        + (point2.2 - point1.2).powi(2);

    println!("{0}", sum.sqrt());
}
