


    pub fn custom_to_lower(text : &mut String){

        let mut new_text = String::new();
        for element in text.chars(){
            new_text.push(element.to_ascii_lowercase());
        }

        *text = new_text;
    }