from boy import Boy 
from girl import Girl 

'''
:param: boy : Boy object
:param: girl : Girl object
:param: happiness: Happiness of the couple determined as the sum of happiness of boy and girl together.
'''


class Couple:
    def __init__(self,boy,girl,happiness,compatibility):
        self.boy = boy
        self.girl = girl
        self.happiness = happiness
        self.compatibility = compatibility
