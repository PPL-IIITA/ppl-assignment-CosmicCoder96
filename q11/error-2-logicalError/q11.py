from utility import giveGifts, valentine,generateBoyList,generateGirlList

def q4():
	boy_list = generateBoyList()
	girl_list = generateGirlList()
	couple_list = giveGifts(boy_list,girl_list)
	print ' Value of k is assumed as 6000'
	k = 6000
	valentine(k,couple_list,boy_list,girl_list)
q4()
