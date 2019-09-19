from functools import partial

def run_func(f):
    f('hello')
    return f

def func(one, two, three):
    print(one, two, three)

part = partial(func, 'one', 'two')

@run_func
def run(arg):
    part(arg)
