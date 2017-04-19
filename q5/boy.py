class Boy:
	def __init__(self,name,attractiveness,budget,intelligence_level,min_attraction_requirement,Type,committed,happiness):
		self.name=name
		self.attractiveness=attractiveness
		self.budget = budget
		self.intelligence_level=intelligence_level
		self.min_attraction_requirement=min_attraction_requirement
		self.Type=Type
		self.committed=committed
		self.happiness=happiness
	def getHappiness(self,girl,total_gifts):
		if self.Type=="MISER":
			self.happiness=self.budget-total_gifts
		elif self.Type=="GENEROUS":
			self.happiness=girl.happiness
		else:
			self.happiness=girl.intelligence_level
		return self.happiness

	def isCommitted(self):
		if self.committed:
			return True
		else:
			return False
	def commit(self):
		self.committed = 1