from utility import giveGifts, valentine,generateBoyList,generateGirlList, calendar
import utility


def q6():
	boy_list = generateBoyList()
	girl_list = generateGirlList()
	couple_list = giveGifts(boy_list,girl_list)
	print ' Value of k is assumed as 5'
	k = 5
	print ' Value of t is assumed as 4'
	t = 4
	calendar(t,k,couple_list,boy_list,girl_list)
q6()
