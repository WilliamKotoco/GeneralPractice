num = input("Digite um numero: ")

try:
    num_float = float(num)
    # if an error occurs in the line above, it will jump to the 
    # except
    print(f'{num} é um número')
except:
    print(f'{num} não é um número')
