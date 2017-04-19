class Gift:
	def __init__(self,price,value,used=False):
		self.price = price
		self.value = value
		self.used = False

class utilityGift(Gift):
	def __init__(self,price,value,used, utility_value,utility_class,Type):
		Gift.__init__(self,price,value)
		self.utility_class = utility_class
		self.utility_value = utility_value
		self.Type = "utility"


class luxuryGift(Gift):
	def __init__(self, price, value,used, difficulty, rating,Type):
		Gift.__init__(self,price,value)
		self.difficulty=difficulty
		self.rating=rating
		self.Type="luxury"

class essentialGift(Gift):
	def __init__(self,price,value,used, Type):
		Gift.__init__(self,price,value)
		self.Type="essential"