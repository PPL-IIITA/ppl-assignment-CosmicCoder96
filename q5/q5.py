from utility import giveGifts,generateBoyList,generateGirlList, k_most_happy_couples

def q5():
	boy_list = generateBoyList()
	girl_list = generateGirlList()
	couple_list = giveGifts(boy_list,girl_list)
	print ' Value of k is assumed as 6'
	k = 6
	k_most_happy_couples(couple_list,k)

q5()

