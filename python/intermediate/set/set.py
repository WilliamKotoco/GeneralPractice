#Sets are mutable but accept only immutable types 

# also there are no duplicated values in a set 

# inspired on math sets. 

s1 = set()
s1.add('Teste')
print(s1, type(s1))

# they do not have indexes and also does not have order.

l1 = [1,1,1,1,2,3,4,5,6]
s = set(l1)
l2 = list(s)
print(l2)

# set has the math operations on sets
# union
# intersection
# difference 
# symetric difference (return itens that are not in both)

