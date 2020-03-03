import collections
# 1.3


def drop_first_last(grades):
    first, *mid, last = grades
    return avg(mid)  # list
