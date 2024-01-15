def testing_kwargs(*args, **kwargs):
    for key, value in kwargs.items():
        print(key, value)

testing_kwargs(name='aa', age=14, salary=1500)

# it is also possible to pass a dictionary as a kwargs

config = {
    'arg1': 1,
    'arg2': 2,
    'arg3': 3,
    'arg4': 4,
}
testing_kwargs(**config)

