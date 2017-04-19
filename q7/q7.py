from utility import giveGifts,generateBoyList,generateGirlList, makeCouples, getGF
from girl import Girl
import utility


def q7():
	boy_list = generateBoyList('boys-list.txt')
	boy_list2 = generateBoyList('boys-list-temp.txt')
	for b in range(0,len(boy_list)/4):
		boy_list2.append(boy_list[b])
	girl_list = generateGirlList()
	couple_list = makeCouples('new', boy_list,girl_list)
	print  'The choice for selecting the type of structure used\n\ 1 for array/linked-list\ 2 for binary search\ 3 for hashing, hashing is chosed here\n'
	choice = 3 
	end_result = getGF(choice,couple_list,boy_list2)
	for i in end_result:
		print i.name
# print end_result
q7()