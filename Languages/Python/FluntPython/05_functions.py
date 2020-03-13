from collections import namedtuple
from functools import partial, reduce
from operator import add, mul, itemgetter
import random

# !functions in python is first class object


def factorial(n):
    '''return n!'''
    return 1 if n < 2 else n*factorial(n-1)


def fac(n):
    return reduce(mul, range(1, n+1))


cc_name = itemgetter(0, 1)
# print(cc_name([5, 4, 3, 2, 1])) # 5,4

# print(factorial.__doc__)


# 5.2 high level functions
# print(reduce(add, range(100)))

class BingoCage:
    def __init__(self):
        super().__init__()

    def __call__(self):
        return random.randint(0, 10)


bingo = BingoCage()
# print(bingo())  # call __call__

# 5.7 keywords


def tag(name, *content, **attrs):
    '''generate tags''',
    pass


def f(a, *, b, c):
    return a, b


# print(f(1, b=10))  # missing c
def clip(text: str, max_len: 'int>0' = 80) -> str:
    '''clip text before max_len
    '''
    end = None
    if len(text) > max_len:
        space_before = text.rfind(' ', end=max_len)
        if space_before > 0:
            end = space_before
        else:
            space_after = text.rfind(' ', max_len)
            if space_after > 0:
                end = space_after
    if end in None:
        end = len(text)
    return text[:end].rstrip()


print(clip.__annotations__)  # save annotations, without extra use

triple = partial(mul, 3)
print(list(map(triple, range(10))))
