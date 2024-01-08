lista = [1,2,3]

val1,val2,val3 = lista
print(val1, val2, val3)

# name1,name2 = ["joao", "maria", "jose"] unpack error, to many values to unpack
# # name1,name2,nome3,nome4 = ["joao", "maria", "jose"] unpack error, to many values to unpack



lista.append(4)
lista.append(5)

val, *remainder = lista
print(val, remainder)

# _ is a convention to ignore the remainder values
val, *_ = lista

_,second_value,*_ = lista 
print(second_value)
