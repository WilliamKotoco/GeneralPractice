# list -> mutable
# tuples -> not mutable, used for reading only, being faster.

lista = ['nome1', 'nome2']
tupla = ('nome1', 'nome2')

# tupla[2] = 'aa' will generate error 
lista_tuple = tuple(lista)
tupla_lista = list(tupla)
print(tupla[1])
