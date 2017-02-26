#include <iostream>
#include <fstream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "MakeCouples.h"
#define NO_OF_BOYS 100
#define NO_OF_GIRLS 50
#define MOST_ATTRACTIVE 0
#define MOST_RICH 1
#define MOST_INTELLIGENT 2
using namespace std;

void MakeCouples::generateCouples()
{
	int i = 0,j=0, selectIndex = -1,couple_count = 0;
bool committed_flag = false;
Boy boys[NO_OF_BOYS];
Girl girls[NO_OF_GIRLS];
Couple couples[NO_OF_GIRLS];
ifstream read_boys_list  ("List_of_boys.txt");
if (read_boys_list.is_open())
{
	while(read_boys_list>> boys[i].name>>boys[i].attractiveness>>boys[i].budget>>boys[i].intelligence_level>>boys[i].min_attraction_requirement>>boys[i].type>>boys[i].committed)
	{
		cout<<boys[i].name<<endl;
		i++;
	}
	read_boys_list.close();

}
i=0;
ifstream read_girls_list ("List_of_Girls.txt");

if (read_girls_list.is_open())
{
	cout <<"It opens\n";
	while(read_girls_list>> girls[i].name>>girls[i].attractiveness>>girls[i].maintainance_budget>>girls[i].intelligence_level>>girls[i].criterion>>girls[i].type>>girls[i].committed)
	{
		cout<<girls[i].name<<1234<<endl;
		i++;

	}
	read_girls_list.close();
}
for(i=0;i<NO_OF_GIRLS;i++)
{
	// cout<<girls[i].name<<endl;
	for(j=0;j<NO_OF_BOYS;j++)
	{
		if(boys[j].committed == 1|| girls[i].maintainance_budget>boys[j].budget || girls[i].attractiveness < boys[j].min_attraction_requirement)
			continue;
		else
		{
			committed_flag = true;
			if(selectIndex == -1)
				selectIndex = j;
			if(girls[i].criterion == MOST_ATTRACTIVE)
			{
				if(boys[j].attractiveness>boys[selectIndex].attractiveness)
				{
					selectIndex = j;
				}
			}
			if(girls[i].criterion == MOST_RICH)
			{
				if(boys[j].budget > boys[selectIndex].budget)
				{
					selectIndex = j;
				}
			}
			if(girls[i].criterion == MOST_INTELLIGENT)
			{
				if(boys[j].intelligence_level>boys[selectIndex].intelligence_level)
				{
					selectIndex = j;
				}
			}
		}
	}
	if(committed_flag == true)
	{
		boys[selectIndex].committed = 1;
		girls[i].committed = 1;
		couples[couple_count].boy = boys[selectIndex];
		couples[couple_count].girl = girls[i];
		couple_count++;
		committed_flag = false;
		cout << "Couple : "<<boys[selectIndex].name<<" "<<girls[i].name<<" "<<i<<endl;
	}
	selectIndex = -1;

}

ofstream couples_list("List_of_Couples.txt");
for(i=0;i<couple_count;i++)
{
	couples_list << couples[i].boy.name<<" "<<couples[i].boy.attractiveness<<" "<<couples[i].boy.budget<<" "<<couples[i].boy.intelligence_level<<" "<<couples[i].boy.min_attraction_requirement<<" "<<couples[i].boy.type<<" "<<couples[i].boy.committed<<" "<<couples[i].girl.name<<" "<<couples[i].girl.attractiveness<<" "<<couples[i].girl.maintainance_budget<<" "<<couples[i].girl.intelligence_level<<" "<<couples[i].girl.criterion<<" "<<couples[i].girl.type<<" "<<couples[i].girl.committed<<endl;
}
}