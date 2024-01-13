lista = [
    {'nome': 'Luiz', 'sobrenome': 'Miranda'},
    {'nome': 'Maria', 'sobrenome': 'Oliveira'},
    {'nome': 'Daniel', 'sobrenome': 'Silva'},
    {'nome': 'Eduardo', 'sobrenome': 'Moreira'},
    {'nome': 'Aline', 'sobrenome': 'Souza'},
]

def print_name(lista):
    for value in lista:
        print(value['nome'], value['sobrenome'])


def sorting(item):
    return item['sobrenome']

print_name(lista)
print()
lista.sort(key=sorting)
print_name(lista)

lista.sort(key=lambda item: item['nome'])
print()
print_name(lista)
