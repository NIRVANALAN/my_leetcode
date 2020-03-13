# Variable scope
import functools
import html
import numbers
import time
from collections import abc

b = 6


def f2(a):
    print(b)  # wrong
    b = 1


def f2(a):
    global b
    print(b)  # 6
    b = 9
# Closure


def make_averager():
    series = []  # ! closure

    def averager(new_value):
        # * series is free variable. not binded var in local scope
        series.append(new_value)
        return sum(series)/len(series)


def improved_make_averager():
    count = 0
    total = 0

    def averager(new_value):
        nonlocal total, count  # failure without nonlocal
        total += new_value
        count += 1  # becomes local after assginment
        return total/count

    return averager


# averager = improved_make_averager()
# print(averager(10))

# decorator


def clock(func):
    @functools.wraps(func)  # copy attributes from func to clocked
    def clocked(*args, **kwargs):
        t0 = time.perf_counter()
        result = func(*args, **kwargs)
        elapsed = time.perf_counter() - t0
        name = func.__name__
        arg_lst = []
        if args:
            arg_lst.append(', '.join(repr(arg) for arg in args))
        if kwargs:
            pairs = ['%s=%r' % (k, w) for k, w in sorted(kwargs.items())]
            arg_lst.append(', '.join(pairs))
        arg_str = ', '.join(arg_lst)  # !
        print('[%0.4fs] %s(%s) -> %r' % (elapsed, name, arg_lst, result))
        return result
    return clocked


@clock
def snooze(seconds):
    time.sleep(seconds)


@clock
def factorial(n):
    # what factorial saved is the reference to clocked
    return 1 if n < 2 else n*factorial(n=n-1)


# snooze(0.5)
# factorial(n=5)

# ! decorator in stdlib # TODO

# cache result with dictionary, decorated function kws should be hashable
# * lru_cache
@functools.lru_cache(maxsize=128, typed=True)
@clock
def fibonacci(n):
    if n < 2:
        return n
    return fibonacci(n-2)+fibonacci(n-1)


# fibonacci(31)
# * singledispatch
@functools.singledispatch
def htmlize(obj):
    content = html.escape(repr(obj))
    return '<pre>{}</pre>'.format(content)


@htmlize.register(numbers.Integral)
def _(n):
    return '<pre>{0} (0x{0:x})</pre>'.format(n)


@htmlize.register(tuple)
@htmlize.register(abc.MutableSequence)
def _(seq):
    return 'sequence rst'


# print(htmlize(5099))
print(htmlize([1, 2, 3]))
