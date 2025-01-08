fn iterate(v: &Vec<i32>) {
    for i in v {
        println!("{i}");
    }
}

fn main() {
    let mut v = vec![10, 20, 30, 40, 50];

    // iterating ready only
    for i in &v {
        println!("{i}");
    }

    // iterating for changing
    //
    for i in &mut v {
        *i += 10;
    }

    iterate(&v);
}
