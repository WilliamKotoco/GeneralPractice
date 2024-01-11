def multiplicator(multiplicator):
    def multiply(num):
        return num * multiplicator
    return multiply



duplicar = multiplicator(2)
triplicar = multiplicator(3)
quadruplicar = multiplicator(4)

# Duplicar, triplicar e quadruplicar lembram o parametro multiplicator quando usada.

# Python closure is a nested function that allows us to access variables of the outer function even after the outer function is closed.
print(duplicar(2), triplicar(2), quadruplicar(4))
