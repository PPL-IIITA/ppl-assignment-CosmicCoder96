#include <iostream>
#include <fstream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "Gift.h"
#include "MakeCouples.h"
using namespace std;
int main ()
{ 
	MakeCouples generator;
	generator.generateCouples();
	int i=0,j,couple_count, minGiftIndex=0,moneySpent = 0,moneyLeft,maxGiftIndex=0;
	bool luxury_gift = false;
	Couple  couples[100];

	Gift gifts[200];
	ifstream couples_file ("List_of_Couples.txt");
	cout<<"Hello\n";
	if(couples_file.is_open())
	{
		while(couples_file>> couples[i].boy.name>>couples[i].boy.attractiveness>>couples[i].boy.budget>>couples[i].boy.intelligence_level>>couples[i].boy.min_attraction_requirement>>couples[i].boy.type>>couples[i].boy.committed>>couples[i].girl.name>>couples[i].girl.attractiveness>>couples[i].girl.maintainance_budget>>couples[i].girl.intelligence_level>>couples[i].girl.criterion>>couples[i].girl.type>>couples[i].girl.committed)
		{
					// cout<< "Hello2";

			
			// cout<<couples[i].boy.name<<" "<<couples[i].boy.attractiveness<<" "<<couples[i].boy.budget<<" "<<couples[i].boy.intelligence_level<<" "<<couples[i].boy.min_attraction_requirement<<" "<<couples[i].boy.type<<" "<<couples[i].boy.committed<<" "<<couples[i].girl.name<<" "<<couples[i].girl.attractiveness<<" "<<couples[i].girl.maintainance_budget<<" "<<couples[i].girl.intelligence_level<<" "<<couples[i].girl.criterion<<" "<<couples[i].girl.type<<" "<<couples[i].girl.committed<<endl;
			i++;
		}
		couple_count = i;
		int total_cost[200]={0};
		int total_value[200]={0};
	couples_file.close();
	}
	i =0;
	ifstream gifts_file ("List_of_Gifts.txt");
	if(gifts_file.is_open())
	{
		while(gifts_file >> gifts[i].price>>gifts[i].price>>gifts[i].type>>gifts[i].luxury_rating>>gifts[i].difficulty>>gifts[i].utility_value>>gifts[i].utility_class>>gifts[i].used)
		{
			cout << gifts[i].price<<" "<<gifts[i].price<<" "<<gifts[i].type<<" "<<gifts[i].luxury_rating<<" "<<gifts[i].difficulty<<" "<<gifts[i].utility_value<<" "<<gifts[i].utility_class<<" "<<gifts[i].used<<endl;
			i++;
		}
	}
	for(i=0;i<couple_count;i++)
	{
		moneySpent = 0;
		moneyLeft = couples[i].boy.budget;
		luxury_gift = false;
		for(j=0;j<200;j++)
		{
			if(gifts[j].price<gifts[minGiftIndex].price && gifts[j].used==0)
			{
				minGiftIndex = j; 
			}
			if(gifts[j].price>gifts[maxGiftIndex].price && gifts[j].used==0)
			{
				maxGiftIndex = j;
			}
		}
		for(j=0;j<200;j++)
		{
			if(couples[i].boy.type == MISER)
			{
				if(gifts[minGiftIndex].price>couples[i].boy.budget || gifts[minGiftIndex].price > moneyLeft || moneySpent > couples[i].girl.maintainance_budget)
					continue;
				else
				{
					gifts[minGiftIndex].used = 1;
					moneySpent += gifts[minGiftIndex].price;
					moneyLeft -= gifts[minGiftIndex].price;
					total_cost[i]+= gifts[minGiftIndex].price;
					total_value[i].value+=gifts[minGiftIndex].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[minGiftIndex].price<<"and value "<<gifts[minGiftIndex].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl;



				}

			}
			else if(couples[i].boy.type == GENEROUS)
			{
				if(gifts[j].price>couples[i].boy.budget ||gifts[minGiftIndex].price > moneyLeft || moneySpent >= couples[i].girl.maintainance_budget)
					continue;
				else
				{
					gifts[j].used = 1;
					moneySpent += gifts[j].price;
					moneyLeft -= gifts[j].price;
					total_cost[i]+= gifts[j].price;
					total_value[i].value+=gifts[j].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<"and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl;
					
				}
			}
			else
			{
				if(gifts[minGiftIndex].price>couples[i].boy.budget || gifts[minGiftIndex].price > moneyLeft || moneySpent > couples[i].girl.maintainance_budget)
					continue;
				else
				{
					if(gifts[j].type == LUXURY && luxury_gift == false)
					{
						gifts[j].used = 1;
						luxury_gift = true;
						moneySpent +=gifts[j].price;
						moneyLeft -= gifts[j].price;
						total_cost[i]+= gifts[j].price;
						total_value[i].value+=gifts[j].value;
						cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<"and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl;

					}
					else
					{
					gifts[j].used = 1;
					moneySpent += gifts[j].price;
					moneyLeft -= gifts[j].price;
					total_cost[i]+= gifts[j].price;
					total_value[i].value+=gifts[j].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<"and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl;

					}

				}
			}
		}
	}

}