from utility import giveGifts, valentine,generateBoyList,generateGirlList

def q4():
	boy_list = generateBoyList()
	girl_list = generateGirlList()
	couple_list = giveGifts(boy_list,girl_list)
	print ' Value of k is assumed as 6'
	k = 6
	valentine(k,couple_list,boy_list,girl_list)
q4()
