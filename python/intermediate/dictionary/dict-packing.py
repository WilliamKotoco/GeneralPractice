person = {
    'name': 'John',
    'age': 14,
}

person_job = {
    'job' : 'Physicist',
    'salary': 5990
}


person_total_info = {**person, **person_job}

print(person_total_info)

