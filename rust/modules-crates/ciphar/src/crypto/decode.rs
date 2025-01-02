pub fn decode_text(encoded: &String) ->  String
{
    let mut result = String::new();

    for element in encoded.chars()
    {
        if element.is_ascii_lowercase(){
            result.push(get_next_letter(element));
        }
        else {
            result.push(element);
        }
    }


    result

}

fn get_next_letter(ch : char) -> char
{
    let base = 'a' as u8;

    let offset = ch as u8 - base;

    (base + ((offset + 26 - 3) % 26)) as char
}
