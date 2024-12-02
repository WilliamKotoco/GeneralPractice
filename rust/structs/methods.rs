#[derive(Debug)]
struct Person {
    name: String,
    age: i16,
}

// everything inside this block will be methods from the Person struct
impl Person {
    // self is an alias for the struct that the implementation block is for
    // using & because we do not want to take ownership
    //
    fn birth_year(&self) -> i16 {
        2024 - self.age
    }

    // passes a immutable borrow of other instance of person.
    // The borrow is immutable because it will be used only for reading
    //
    fn is_older(&self, other_person: &Person) -> bool {
        self.age > other_person.age
    }
}

fn main() {
    let person = Person {
        name: String::from("thread_local!(static STATIC: Type = init);"),
        age: 14,
    };

    println!("{person:?}");

    let birth_year = person.birth_year();

    println!("And was born in {birth_year}");

    let p2 = Person {
        name: String::from("Young"),
        age: 10,
    };
    let p3 = Person {
        name: String::from("Older"),
        age: 20,
    };

    println!("{0} and {1}", person.is_older(&p2), person.is_older(&p3));
}
