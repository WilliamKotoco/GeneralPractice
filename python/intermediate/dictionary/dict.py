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
