import random
import string
from boy import Boy, Geek , Miser, Generous
from girl import Girl, Choosy, Desperate, Normal
from couple import Couple
from gift import utilityGift, luxuryGift, essentialGift
from random import randint

def randomName(size=6, chars=string.ascii_uppercase):
	return ''.join(random.choice(chars) for _ in range(size))
	

def generateBoyList():
	boyList=[]
	f=open('boys-list.txt','w')
	for i in range(1,1000):
		name = randomName();
		committed = 0;
		happiness = 0;
		attractiveness = randint(1,10)
		budget = randint(1000,10000)
		intelligence_level = randint(1,10)
		min_attraction_requirement = randint(1,10)
		r = randint(0,2)
		if r==0:
			temp = Geek(name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
		elif r==1:
			temp = Miser(name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
		else:
			temp = Generous(name,attractiveness,budget,intelligence_level,min_attraction_requirement,committed,happiness)
		boyList.append(temp)
		f.write(name+ ' ' +str(attractiveness)+ ' ' +str(budget)+ ' ' +str(intelligence_level)+ ' ' +str(min_attraction_requirement)+ ' ' + ' ' +str(committed)+ ' ' +str(happiness) +'\n')
	f.close()
	return boyList




def generateGirlList():
	girlList=[]
	f = open('girls-list.txt','w')
	for i in range(1,1000):
		name = randomName();
		attractiveness = randint(1,10)
		committed = 0;
		happiness = 0;
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
			temp = Choosy(name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
		elif r==1:
			temp = Normal(name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)

		else:
			temp = Desperate(name,attractiveness,maintainance_budget,intelligence_level,criterion,committed,happiness)
			

		girlList.append(temp)
		f.write(name+ ' ' +str(attractiveness)+ ' ' +str(maintainance_budget)+ ' ' +str(intelligence_level)+ ' ' +str(criterion)+ ' ' +' ' +str(committed)+ ' ' +str(happiness) +'\n')
	return girlList

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
	f.close()
	return gift_list


# couple_list = []

def makeCouples(mode,boy_list,girl_list):
	
	couple_list = []
	commitFlag = False
	i=0
	if mode =='append':
		f = open('couple-list.txt', 'a')
	else:
		f = open('couple-list.txt','w')
	for g in girl_list:
		commitFlag = False
		for b in boy_list:
			if b.isCommitted() or g.isCommitted() or  g.maintainance_budget> b.budget or g.attractiveness < b.min_attraction_requirement:
				continue
			else:
				commitFlag = True
				selectedBoy = b;
				if g.criterion=='attractive':
					if b.attractiveness > selectedBoy.attractiveness:
						selectedBoy = b
				if g.criterion == 'rich':
					if b.budget>selectedBoy.budget:
						selectedBoy = b
				if g.criterion == 'intelligent':
					if b.intelligence_level>selectedBoy.intelligence_level:
						selectedBoy = b;
		if commitFlag:
			i+=1
			selectedBoy.commit()
			g.commit()
			happiness = 1000
			compatibility = 1000
			temp = Couple(selectedBoy,g,happiness,compatibility)
			couple_list.append(temp)
			f.write('Couple formed ' + temp.boy.name + ' committed with ' + temp.girl.name + '\n')
			print('Couple formed ' + temp.boy.name + ' committed with ' + temp.girl.name + '\n')

	f.close()
	return couple_list

def giveGifts(boy_list,girl_list):
	couple_list = makeCouples('new',boy_list,girl_list)
	gift_list = generateGiftList()
	print len(couple_list)
	print len(gift_list)
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
			if c.boy.__class__.__name__=='Miser':
				if minGift.used==False:
					minGift.used==True
					moneySpent+=minGift.price
					moneyLeft-=minGift.price
					totalCost+=minGift.price
					# totalValue+=minGift.value
					print ('Gift for boy type miser exchanged')
			elif c.boy.__class__.__name__=='Generous':
				g.used=True
				moneySpent+=g.price
				moneyLeft-=g.price
				totalCost+=g.price
				totalValue+=g.value
				print ('Gift for boy type Generous exchanged')
			else:
				if g.Type=='luxury' and luxuryFlag==False:
					g.used=True
					moneySpent+=g.price
					moneyLeft-=g.price
					totalCost+=g.price
					totalValue+=g.value
					luxuryFlag=True
					print ('Gift for boy type GeeK luxury  exchanged')

				elif luxuryFlag==True:
					g.used=True
					moneySpent+=g.price
					moneyLeft-=g.price
					totalCost+=g.price
					totalValue+=g.value
					print ('Gift for boy type 3 Geek luxury  exchanged')

				else:
					continue
		c.happiness = c.boy.getHappiness(c.girl,totalCost) + c.girl.getHappiness(c.boy,totalValue,totalValue)
		# print 'happiness of the couple ' + c.boy.name + ' and ' + c.girl.name + ' is ' + str(c.happiness) +'\n'
	return couple_list






# giveGifts()
def k_most_happy_couples(k, couple_list):	
	couple_list.sort(key = lambda x: x.happiness, reverse = True)
	i = 0
	print 'The '+str(k)+'  happiest couples along with their happiness are \n'
	for c in couple_list:
		i+=1
		print c.boy.name + ' ' +c.girl.name+' ' +str(c.happiness)
		if i==k:
			break
# k_most_happy_couples(couple_list)

def k_least_happy_couples(couple_list):
	couple_list.sort(key = lambda x: x.happiness, reverse = False)
	return couple_list

# k_least_happy_couples(couple_list)



# valentine(10,couple_list)
