import math
class Girl:
	'''
	:param name: name attribute of the Girl object
	:param attractiveness: attractiveness of the Girl
	:param maintainance_budget: maintainance Budget the girl requires
	:param intelligence_level: Intelligence level of the Girl
	:param min_attraction_requirement: Attraction Requirement of the girl
	:param committed: Commitment status of the Girl 0-single 1-committed
	:param happiness: Happiness of the Girl

	'''

	'''
	Contruct for Girl '''
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		self.name=name
		self.attractiveness=attractiveness
		self.maintainance_budget = maintainance_budget
		self.intelligence_level=intelligence_level
		self.criterion=criterion
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

	#Subclass of Girl class for Choosy
class Choosy(Girl):
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		Girl.__init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
	def getHappiness(self,boy,total_gifts, total_gift_value):
		self.happiness=math.log(abs(self.maintainance_budget-total_gifts))
		return self.happiness
		#Subclass of Girl class for Normal

class Normal(Girl):
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		Girl.__init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
	def getHappiness(self,boy,total_gifts, total_gift_value):
		self.happiness=self.maintainance_budget-total_gifts+ total_gift_value
		return self.happiness
			#Subclass of Girl class for Desperate

class Desperate(Girl):
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		Girl.__init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
	def getHappiness(self,boy,total_gifts, total_gift_value):
		self.happiness=math.exp((total_gifts-self.maintainance_budget)%10)
		return self.happiness




		# 	self.happiness=(int)exp(total_gifts-self.maintainance_budget)%5
