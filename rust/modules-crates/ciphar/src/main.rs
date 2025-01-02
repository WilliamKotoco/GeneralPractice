use crypto::encode::encode_text;

use crypto::decode::decode_text;


mod crypto;

mod text;

fn main() {
    let mut message = String::from("Hello World I am using whatsapp");

    message = encode_text(&mut message);


    println!("Encoded message: {message}");

    let  decoded = decode_text(&message);

    println!("Decoded message: {decoded}");
}
