secret_word = "haru"

remaining_letters  = list(secret_word)
lives = 5

while (lives):
    guess = input("Enter a letter: ")
    if (guess in secret_word):
        remaining_letters.remove(guess)
        print_str = secret_word

        for letter in remaining_letters:
            print_str = print_str.replace(letter, '*')

       
        print(print_str)
        if(print_str == secret_word):
            print("Voce ganhou!")
            break;
    else:
        lives -= 1
        print(f'Tente novamente, tem {lives} vidas')
else:
    print("Você perdeu")
