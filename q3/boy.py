class Boy:
	'''
	:param boy: a boy object
	:param name: name attribute of the boy object
	:param attractiveness: attractiveness of the boy
	
	'''
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		self.name=name
		self.attractiveness=attractiveness
		self.budget = budget
		self.intelligence_level=intelligence_level
		self.min_attraction_requirement=min_attraction_requirement
		self.committed=committed
		self.happiness=happiness

	def isCommitted(self):
		if self.committed:
			return True
		else:
			return False
	def commit(self):
		self.committed = 1

class Geek(Boy):
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		Boy.__init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
	def getHappiness(self,girl,total_gifts):
		self.happiness=girl.intelligence_level
		return self.happiness
class Miser(Boy):
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		Boy.__init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
	def getHappiness(self,girl,total_gifts):
		self.happiness=self.budget-total_gifts
		return self.happiness

class Generous(Boy):
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		Boy.__init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
	def getHappiness(self,girl,total_gifts):
		self.happiness=girl.happiness
		return self.happiness


