import math
from math import hypot
import collections

Cards = collections.namedtuple('Cards', ['rank', 'suit'])


class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)]
    suits = 'spades diamonds clubs hearts'.split()

    def __init__(self):
        super().__init__()
        self._cards = [Cards(rank, suit)
                       for rank in self.ranks for suit in self.suits]

    def __len__(self):
        return len(self._cards)

    def __getitem__(self, position):  # * slice & iterable
        return self._cards[position]
        # ! for list/tuple/str, python will call PyVarObjec->ob_size, which is much faster

    # def __contains__(self, ele):
    #     pass


# suit_val = {'spades': 3, 'hearts': 2, 'diamonds': 1, 'clubs': 0}
suit_val = dict(spades=3, hearts=2, diamonds=1, clubs=0)


def deckSort(card):
    rank_val = FrenchDeck.ranks.index(card.rank)
    return rank_val * len(FrenchDeck.suits) + suit_val[card.suit]


deck = FrenchDeck()

# for card in sorted(deck, key=deckSort):
#     print(card)


class Vector:

    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):  # * to be unambiguous, __str__ to be readable
        # return super().__repr__()
        return 'Vector (%r,%r)' % (self.x, self.y)
    # def __str__(self):  # * to be readable
    #     return super().__str__()
    # * their difference: https://stackoverflow.com/questions/1436703/difference-between-str-and-repr

    def __abs__(self):
        return hypot(self.x, self.y)

    def __bool__(self):
        # return bool(abs(self))
        return bool(self.x or self.y)

    def __add__(self, other):
        return Vector(self.x+other.x, self.y+other.y)

    def __mul__(self, other):
        return Vector(self.x*other.x, self.y*other.y)
