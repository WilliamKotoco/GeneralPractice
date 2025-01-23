fn get_largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

fn main() {
    let lista = [10, 20, 30, 40];

    let result = get_largest(&lista);

    println!("{result}")
}
