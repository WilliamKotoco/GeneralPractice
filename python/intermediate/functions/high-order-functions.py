#a function in python has the same "type" as any other data 

#Python closure is a nested function that allows us to access variables of the outer function even after the outer function is closed.


# create and returns a function for adding or subtracting
def sum_or_sub(a):
    if (a == 1):
        def soma(a,b):
            return a+b
        return soma 
    else:
        def sub(a,b):
            return a-b
        return sub 


funcao = sum_or_sub(1)
funcao2 = sum_or_sub(3)
print(funcao(2,3))
print(funcao2(3,4))
