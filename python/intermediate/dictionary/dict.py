# Par key-value map, classic dsa, just like the hashmap in java

# Usa chaves {} - or the dict class to create them 

# Keys must be immutable: str, float, bool, tuple

# values can be any type, even another dictionary.

record = {
    'name': "Willl",
    'age': 14,
    'addr': ('sjrp', 'sp', '3004')
}


print(record, type(record))
print()
print(record['age'], type(record['age']))
print()
print(record['addr'], type(record['addr']))
print()
print(record['addr'][0])
print()

# len - returns amount of Keys
# keys - return an iterable with keys 
# values - return an iterable with values 
#items - return an iterable with keys and values 
# setdefault - adds a value if the key does not exist
#copy - copy the immutable values to another dictinaory and adds a pointer to the mutabble values 

#deepcopy - copy everything even the mutable values. Must import the copy module and use copy.deepcopy()
print(list(record.keys()))
print(list(record.values()))



for item in record.items():
    print(list(item))
