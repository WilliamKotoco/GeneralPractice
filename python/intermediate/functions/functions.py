# Functions return None by default.
def teste():
    print("test1")
    print("test2")


def Print(a,b,c):
    print(a,b,c)
teste()


def order(a, b):

    print(f'first: {a} \n last: {b}')


def default_values(a,b, c='Olá'):
    print(a,b,c)

y = 3

def largest():
    print("largest")
    def inside():
        global y # indicates to use the global variable y
        print(y)
    inside()


Print('zé', 30, 'cu')
print(teste())

order(b='first', a='second')
default_values('jao','carlos','mateus')
default_values('joao', 'carlos')
largest()
