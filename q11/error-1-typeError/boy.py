class Boy:
	'''
	:param boy: a boy object
	:param name: name attribute of the boy object
	:param attractiveness: attractiveness of the boy
	:param budget: Budget the boy has
	:param intelligence_level: Intelligence level of the boy
	:param min_attraction_requirement: Attraction Requirement of the boy
	:param committed: Commitment status of the boy 0-single 1-committed
	:param happiness: Happiness of the boy

	'''

	'''
	Contruct for Boy '''
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		self.name=name
		self.attractiveness=attractiveness
		self.budget = budget
		self.intelligence_level=intelligence_level
		self.min_attraction_requirement=min_attraction_requirement
		self.committed=committed
		self.happiness=happiness
		# Method to find commitment status
	def isCommitted(self):
		if self.committed:
			return True
		else:
			return False
		# Method to change the commitment status to committed
	def commit(self):
		self.committed = 1

		#Subclass of Boy class for geek
class Geek(Boy):
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		Boy.__init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
	def getHappiness(self,girl,total_gifts):
		self.happiness=girl.intelligence_level
		return self.happiness
		#Subclass of Boy class for geek

class Miser(Boy):
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		Boy.__init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
	def getHappiness(self,girl,total_gifts):
		self.happiness=self.budget-total_gifts
		return self.happiness
		#Subclass of Boy class for geek

class Generous(Boy):
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness):
		Boy.__init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
	def getHappiness(self,girl,total_gifts):
		self.happiness=girl.happiness
		return self.happiness


