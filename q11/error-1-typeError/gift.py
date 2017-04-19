class Gift:
    '''
    :param: price : Price of the gift
    :param: value: Value of the gift
    '''
    def __init__(self,price,value,used=False):
        self.price = price
        self.value = value
        self.used = False
    '''
    utlity Gift - a subClass of gift
    '''


class utilityGift(Gift):
    def __init__(self,price,value,used, utility_value,utility_class,Type):
        Gift.__init__(self,price,value)
        self.utility_class = utility_class
        self.utility_value = utility_value
        self.Type = "utility"
    '''
    luxuryGift- a subcClass of gift
    '''


class luxuryGift(Gift):
    def __init__(self, price, value,used, difficulty, rating,Type):
        Gift.__init__(self,price,value)
        self.difficulty=difficulty
        self.rating=rating
        self.Type="luxury"
    '''
    essentialGift = a subclass of Gift
    '''


class essentialGift(Gift):
    def __init__(self,price,value,used, Type):
        Gift.__init__(self,price,value)
        self.Type="essential"