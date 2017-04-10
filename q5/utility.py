import random
import string
from boy import Boy 
from girl import Girl 
from couple import Couple
from gift import utilityGift, luxuryGift, essentialGift
from random import randint

def randomName(size=6, chars=string.ascii_uppercase):
	return ''.join(random.choice(chars) for _ in range(size))
	
boyList=[]
def generateBoyList():
	f=open('boys-list.txt','w')
	for i in range(1,500):
		name = randomName();
		attractiveness = randint(1,10)
		budget = randint(1000,10000)
		intelligence_level = randint(1,10)
		min_attraction_requirement = randint(1,10)
		r = randint(0,2)
		if r==0:
			Type = "geek"
		elif r==1:
			Type = "miser"
		else:
			Type = "generous"

		committed = 0;
		happiness = 0;
		temp = Boy(name,attractiveness,budget,intelligence_level,min_attraction_requirement,Type,committed,happiness)
		boyList.append(temp)
		#print(name,attractiveness,budget,intelligence_level,min_attraction_requirement,Type,committed,happiness)
		f.write(name+ ' ' +str(attractiveness)+ ' ' +str(budget)+ ' ' +str(intelligence_level)+ ' ' +str(min_attraction_requirement)+ ' ' +Type+ ' ' +str(committed)+ ' ' +str(happiness) +'\n')
	f.close()
	boyList.sort(key = lambda x: x.attractiveness, reverse = True)
	return boyList




girlList=[]
def generateGirlList():
	f = open('girls-list.txt','w')
	for i in range(1,500):
		name = randomName();
		attractiveness = randint(1,10)
		maintainance_budget = randint(1000,10000)
		intelligence_level = randint(1,10)
		r = randint(0,2)
		if r==0:
			criterion = "intelligent"
		elif r==1:
			criterion = "attractive"
		else:
			criterion = "rich"

		r = randint(0,2)
		if r==0:
			Type = "choosy"
		elif r==1:
			Type = "normal"
		else:
			Type = "desperate"

		committed = 0;
		happiness = 0;
		temp = Girl(name,attractiveness,maintainance_budget,intelligence_level,criterion,Type,committed,happiness)
		girlList.append(temp)
		
			#print('Name','Attractiveness','Maintainance Budget', 'intelligence level', 'Criterion', 'Type','Committed','Happiness')
		#print(name,attractiveness,maintainance_budget,intelligence_level,criterion,Type,committed,happiness)
		f.write(name+ ' ' +str(attractiveness)+ ' ' +str(maintainance_budget)+ ' ' +str(intelligence_level)+ ' ' +str(criterion)+ ' ' +Type+ ' ' +str(committed)+ ' ' +str(happiness) +'\n')
	f.close()
	girlList.sort(key = lambda x: x.maintainance_budget, reverse = False)
	return girlList

gift_list= []
def generateGiftList():
	gift_list = []
	f = open('gift-list.txt','w')
	for i in range(1,1000):
		price = randint(200,1000)
		value = randint(200,1000)
		r = randint(0,3)
		Type =''
		if r==0:
			utility_class = randint(1,10)
			utility_value = randint(1,10)
			Type = "utility"
		elif r==1:
			difficulty= randint(1,10)
			rating = randint(1,10)
			Type = "luxury"
		else:
			Type = "essential"
		if Type =="utility":
			temp = utilityGift(price,value,False,utility_value,utility_class,Type)
		elif Type == "luxury":
			temp = luxuryGift(price,value,False,difficulty, rating,Type)
		else:
			temp = essentialGift(price,value,False,Type)
		gift_list.append(temp)
		f.write(str(temp.price) +' ' + str(temp.value) + ' ' +  temp.Type + ' ' + str(temp.used)+'\n')
		#print Type
	f.close()
	return gift_list


couple_list = []
boy_list = generateBoyList()
girl_list = generateGirlList()
def makeCouples(mode):
	
	# couple_list = []
	commitFlag = False
	i=0
	if mode =='append':
		f = open('couple-list.txt', 'a')
	else:
		f = open('couple-list.txt','w')
	for i in range(0,len(boy_list)):
		if i%2==0:
			# print i
			for g in girl_list:
				if g.isCommitted():
					continue
				commitFlag = False
				for b in boy_list:
					if b.isCommitted()  or  g.maintainance_budget> b.budget or g.attractiveness < b.min_attraction_requirement:
						continue
					else:
						commitFlag = True
						selectedBoy = b;
				if commitFlag:
					selectedBoy.commit()
					g.commit()
					happiness = 1000
					compatibility = 1000
					temp = Couple(selectedBoy,g,happiness,compatibility)
					couple_list.append(temp)
					f.write('Couple formed ' + temp.boy.name + ' committed with ' + temp.girl.name + '\n')
					break
		else:
			# print i
			for b in boy_list:
				if b.isCommitted():
					continue
				commitFlag = False
				for g in girl_list:
					if  g.isCommitted() or  g.maintainance_budget> b.budget or g.attractiveness < b.min_attraction_requirement:
						continue
					else:
						commitFlag = True
						selectedGirl = g;
				if commitFlag:
					selectedGirl.commit()
					b.commit()
					happiness = 1000
					compatibility = 1000
					temp = Couple(b,selectedGirl,happiness,compatibility)
					couple_list.append(temp)
					f.write('Couple formed ' + temp.boy.name + ' committed with ' + temp.girl.name + '\n')
					break
				if commitFlag:
					break

	f.close()
	return couple_list

def giveGifts():
	couple_list = makeCouples('new')
	gift_list = generateGiftList()
	for c in couple_list:
		totalCost=0
		totalValue=0
		moneySpent = 0
		moneyLeft = c.boy.budget
		luxuryFlag=False
		for j in gift_list:
			if j.used == False:
				minGift = j
				maxGift = j
				break
		for j in gift_list:
			if j.price < minGift.price and j.used==False:
				minGift = j
			if j.price > maxGift.price and maxGift.used == False:
				maxGift = j
		for g in gift_list:
			if g.used == True  or minGift.price > moneyLeft or moneySpent > c.girl.maintainance_budget:
				continue
			if c.boy.Type=='miser':
				if minGift.used==False:
					minGift.used==True
					moneySpent+=minGift.price
					moneyLeft-=minGift.price
					totalCost+=minGift.price
					totalValue+=minGift.value
					#print ('Gift for boy type miser exchanged')
			elif c.boy.Type=='generous':
				g.used=True
				moneySpent+=g.price
				moneyLeft-=g.price
				totalCost+=g.price
				totalValue+=g.value
				#print ('Gift for boy type Generous exchanged')
			else:
				if g.Type=='luxury' and luxuryFlag==False:
					g.used=True
					moneySpent+=g.price
					moneyLeft-=g.price
					totalCost+=g.price
					totalValue+=g.value
					luxuryFlag=True
					#print ('Gift for boy type 3 luxury  exchanged')

				elif luxuryFlag==True:
					g.used=True
					moneySpent+=g.price
					moneyLeft-=g.price
					totalCost+=g.price
					totalValue+=g.value
					#print ('Gift for boy type 3 non luxury  exchanged')

				else:
					continue
		c.happiness = c.boy.getHappiness(c.girl,totalCost) + c.girl.getHappiness(c.boy,totalValue,totalValue)
		#print 'happiness of the couple ' + c.boy.name + ' and ' + c.girl.name + ' is ' + str(c.happiness) +'\n'






giveGifts()
# makeCouples('new')
def k_most_happy_couples(couple_list,k):	
	couple_list.sort(key = lambda x: x.happiness, reverse = True)
	i=0
	for c in couple_list:
		i+=1
		print c.boy.name + ' is in relationship with ' + c.girl.name + ' with happiness: ' + str(c.happiness)
		if i==k:
			break
k_most_happy_couples(couple_list, 20)


