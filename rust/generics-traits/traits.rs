// Traits is the similar concept of interface: define shared behaviour in an
// abstract way

trait Summary {

    // instead of only defining the function/
    // you could write an default implementation for every struct that
    // do not override it.
    fn summarize(&self) -> String;
}

struct News {
    author: String,
    journal: String,
    content: String,
}

impl Summary for News {
    fn summarize(&self) -> String {
        format!("{}, by {} in {}", self.content, self.author, self.journal)
    }
}

struct Tweet {
    username: String,
    content: String,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
}


// we can define functions that accept only objects that implements
// the Summary trait
fn notification(item: &impl Summary){
        println!("New notification: {}", item.summarize());
}

// in this way we can force two itens that implements the same trait to be the same.
fn double_notifiaton<T: Summary>(item1: &T, item2: &T){
    println!("example");
}


// or <T: Summary + Display>(item: &T)
fn two_impls(item: &(impl Summary + Display)){
    println!("Examle");
}



/// Using where clauses when you have to many traits 
/// 
 fn some_function<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32{
    unimplemented!();
 }


 // can be rewriten to 
 fn some_function<T, U>(t: &T, u: &U) -> i32
where
    T: Display + Clone,
    U: Clone + Debug,
{
    unimplemented!()
}


// you can return traits in function: 
// you return some struct that implements a certain trait, without having to specify
fn returns_summarizable() -> impl Summary{
    unimplemented!();
}

fn main() {
    let ex1 = Tweet {
        username: String::from("richard_fares69"),
        content: String::from("The new Castlevania series is amazing"),
    };


    let ex2 = News{
        author: String::from("Ricardo Fares"),
        journal: String::from("Geek Rust Fanbase"),
        content: String::from("The new Castlevania is a good series"),
    };


    let summary1 = ex1.summarize();

    let summary2 = ex2.summarize();

    println!("{summary1}");

    println!("{summary2}");
}
