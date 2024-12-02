#[derive(Debug)]
struct Movie {
    name: String,
    release_year: i16,
    director: String,
    profit: f32,
}

fn main() {
    let imaginary_movie = Movie {
        name: String::from("Imaginary Movie"),
        release_year: 2034,
        director: String::from("David Night"),
        profit: 2343.34,
    };

    println!("Movies info: ");
    println!("Name: {0}", imaginary_movie.name);
    println!("Release year: {0}: ", imaginary_movie.release_year);
    println!("Director: {0}: ", imaginary_movie.director);
    println!("Profit: {0}: ", imaginary_movie.profit);

    // because we used the derive Debug in the first line, it is possible to print the struct
    // directly
    println!("Movie is {imaginary_movie:?}");

    let unknown_movie = template_movie(
        String::from("A volta dos que não foram"),
        String::from("Desconhecido da Silva"),
    );

    println!(
        "New movie name: {0} \n  Profit: {1}",
        unknown_movie.name, unknown_movie.profit
    );
}

/// creates a template movie initializin the name and the director
/// release year and profit are unknown information
fn template_movie(name: String, director: String) -> Movie {
    Movie {
        name,
        release_year: -1,
        director,
        profit: 0.0,
    }
}
