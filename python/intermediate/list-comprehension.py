# create lists from iterables.


# it can be also used in dictionary and sets
import math
list1 = [numero * 2 for numero in range(10)]
print(list1)

products_prices = {
    'apple': 1.00,
    'banana': 0.75,
    'orange': 1.25,
    'grapes': 2.50,
    'chocolate': 3.00,
    'milk': 2.20,
    'bread': 1.80,
    'eggs': 2.50,
    'cheese': 4.50,
    'coffee': 5.00
}

prices = [value for value in products_prices.values()]

print(prices)


# increasing the value in prices 

print() 
inc_prices = [preco * 1.5 for preco in products_prices.values()]
print(inc_prices)


inc_cond_prices = [preco * 1.5 if preco > 20 else preco  for preco in products_prices.values()]

print(inc_cond_prices)

print()


#filtering data in a list compreehesion


# adds every perfect square from range 0 to 100
perfect_squares = [n for n in range(100) if math.ceil(math.sqrt(n)) == math.floor(math.sqrt(n))]
print()
print(perfect_squares)

detailed_perfect_squares = [(n,math.sqrt(n)) for n in perfect_squares ]
print()
print(detailed_perfect_squares)



