use std::process::exit;

use crate::text::{self, custom_to_lower};

pub fn encode_text(original: &mut String) -> String {
    custom_to_lower(original);

    let mut result = String::new();

    for element in original.chars() {
        if element.is_ascii_lowercase() {
            result.push(get_next_letter(element));
        }
        else {
            result.push(element);
        }
    }

    result
}

fn get_next_letter(ch: char) -> char {
    let base = 'a' as u8;

    let offset = ch as u8 - base;

    (base + ((offset + 3) % 26)) as char
}

//    }
