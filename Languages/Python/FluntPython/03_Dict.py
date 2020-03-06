from collections import abc, UserDict
import dis
from unicodedata import name


my_dict = {}
print(isinstance(my_dict, abc.Mapping))  # True

# Cosntruct dict
a = dict(one=1, two=2, three=3)
b = {'one': 1, 'two': 2, 'three': 3}
c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
d = dict([('one', 1), ('two', 2), ('three', 3)])
e = dict(b)
print(a == b == c == d == e)


class StrKeyDict(UserDict):
    def __missing__(self, key):
        if isinstance(key, str):
            raise KeyError
        else:
            return self[str(key)]

    def __contains__(self, key):
        return str(key) in self.data

    def __setitem__(self, key, item):
        self.data[str(key)] = item
        # return super().__setitem__(key, item)


# Set
num = {1, 2, 3, 4, 5}  # ! faster than set(1,2,3,4,5)
# print(type(num))  # 'set'
character = {'a', 'b', 'c'}
(dis.dis('num={1,2,3}'))
'''
  1           0 LOAD_CONST               0 (1)
              2 LOAD_CONST               1 (2)
              4 LOAD_CONST               2 (3)
              6 BUILD_SET                3
              8 STORE_NAME               0 (num)
             10 LOAD_CONST               3 (None)
             12 RETURN_VALUE
'''

# {'×', '§', '$', '©', '>', '+', '®', '<', '±', '%', '÷', '¢', '¬', '£', 'µ', '°', '¤', '=', '¶', '#', '¥'}
print({chr(i) for i in range(32, 256) if 'SIGN' in name(chr(i), '')})

print(num | character)  # {1, 2, 3, 4, 5, 'c', 'a', 'b'}
'''
num &= character # intersection
num |= character # union
num -= character # difference
num ^= character  # (A-B) | (B-A)  symmetric difference
num <= character # issubset
'''
