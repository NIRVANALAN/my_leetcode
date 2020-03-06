# import array
import pdb
from array import array
from random import random, choices
import timeit
size = 10**5

haystack = array('d', (random() for i in range(size)))
needles = choices(haystack.tolist(), k=500)
needles += [random() for i in range(500)]
needles = array('d', needles)
haystack = dict.fromkeys(haystack)


def speed_test():
    found = 0
    for i in needles:
        if i in haystack:
            found += 1
    print(found)


# print(timeit.timeit('"-".join(str(n) for n in range(100))', number=10000))
print(timeit.timeit(speed_test, number=1))
