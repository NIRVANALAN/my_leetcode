import array
import collections

# list generation
symbols = '$¢£¥€¤'
beyond_ascii = [ord(x) for x in symbols if ord(x) > 127]
beyond_ascii = list(filter(lambda x: x > 127, map(ord, symbols)))  # * the same

# str bytes tuple # * not iterable
