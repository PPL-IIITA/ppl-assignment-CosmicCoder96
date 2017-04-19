class Girl:
	def __init__(self,name,attractiveness,maintainance_budget,intelligence_level,criterion,Type,committed,happiness):
		self.name=name
		self.attractiveness=attractiveness
		self.maintainance_budget = maintainance_budget
		self.intelligence_level=intelligence_level
		self.criterion=criterion
		self.Type=Type
		self.committed=committed
		self.happiness=happiness
	def getHappiness(self,boy,total_gifts, total_gift_value):
		if self.Type=="CHOOSY":
			self.happiness=log(abs(self.maintainance_budget-total_gifts))
		elif self.Type=="NORMAL":
			self.happiness=self.maintainance_budget-total_gifts+ total_gift_value
		else:
			self.happiness=self.maintainance_budget-total_gifts+ total_gift_value
		return self.happiness
		# 	self.happiness=(int)exp(total_gifts-self.maintainance_budget)%5
	def isCommitted(self):
		if self.committed:
			return True
		else:
			return False
	def commit(self):
		self.committed = 1