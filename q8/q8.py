from utility import giveGifts, valentine,generateBoyList,generateGirlList
import utility

def q8():
	boy_list = generateBoyList()
	girl_list = generateGirlList()
	couple_list = giveGifts(boy_list,girl_list,2)
q8()