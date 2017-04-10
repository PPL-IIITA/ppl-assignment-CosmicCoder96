from utility import giveGifts, valentine,generateBoyList,generateGirlList,makeCouples
import utility

def q9():
	boy_list = generateBoyList()
	girl_list = generateGirlList()
	print 'The value of k has been chosen as 5'
	k = 5
	couple_list = giveGifts(boy_list,girl_list,k)
q9()