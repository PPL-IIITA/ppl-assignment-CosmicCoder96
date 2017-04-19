import math
class Girl:
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		self.name=name
		self.attractiveness=attractiveness
		self.maintainance_budget = maintainance_budget
		self.intelligence_level=intelligence_level
		self.criterion=criterion
		self.committed=committed
		self.happiness=happiness
	
	def isCommitted(self):
		if self.committed:
			return True
		else:
			return False
	def commit(self):
		self.committed = 1
class Choosy(Girl):
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		Girl.__init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
	def getHappiness(self,boy,total_gifts, total_gift_value):
		self.happiness=math.log(abs(self.maintainance_budget-total_gifts))
		return self.happiness
class Normal(Girl):
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		Girl.__init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
	def getHappiness(self,boy,total_gifts, total_gift_value):
		self.happiness=self.maintainance_budget-total_gifts+ total_gift_value
		return self.happiness
class Desperate(Girl):
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness):
		Girl.__init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
	def getHappiness(self,boy,total_gifts, total_gift_value):
		self.happiness=math.exp((total_gifts-self.maintainance_budget)%25)
		return self.happiness




		# 	self.happiness=(int)exp(total_gifts-self.maintainance_budget)%5
