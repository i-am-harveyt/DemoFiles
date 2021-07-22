# 9-13
# from collections import OrderedDict

# dictionaries = OrderedDict()

# dictionaries['var'] = 'variables'
# dictionaries['list'] = 'array in python'
# dictionaries['tuple'] = "I'm not very sure what it is but it's kinda strange"
# dictionaries['dictionary'] = "You're a map, right?"
# dictionaries['for'] = 'for loop, haha'

# for key, mean in dictionaries.items():
#     print(key + ': ' + mean)

# 9-14
from random import randint

class Die(object):
    def __init__(self, points):
        self.points = points
    def roll_die(self):
        out = randint(1, self.points)
        print(out)

six = Die(6)
six.roll_die()
ten = Die(10)
ten.roll_die()
twenty = Die(20)
twenty.roll_die()
