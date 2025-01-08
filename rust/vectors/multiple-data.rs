enum TypesInVector {
    Int(i32),
    Float(f32),
    Text(String),
}
fn main() {
    let vector = vec![
        TypesInVector::Int(3),
        TypesInVector::Float(43.53),
        TypesInVector::Text(String::from("Texto Bom")),
    ];

    for i in &vector {
        match i {
            TypesInVector::Int(val) => println!("{}", val),
            TypesInVector::Float(val) => println!("{}", val),
            TypesInVector::Text(val) => println!("{}", val),
        }
    }
}
