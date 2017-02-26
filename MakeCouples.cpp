#include <iostream>
#include <fstream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "MakeCouples.h"
#include "Gift.h"
#define NO_OF_BOYS 100
#define NO_OF_GIRLS 50
#define MOST_ATTRACTIVE 0
#define MOST_RICH 1
#define MOST_INTELLIGENT 2
using namespace std;
/*This is the class primarily responsible for the functioning of the program and makes use of Boy, Girl, Couple
 and Gift classes to solve problems. */


//generateCouples() function is responsible for generating various random couples and store them in a specified text file.
void MakeCouples::generateCouples()
{
/* Generating couples requires the function to read from the list of boys and girls from their respective files and then 
based on the criterion and preference as per the requirements, form couples */
int i = 0,j=0, selectIndex = -1,couple_count = 0;
bool committed_flag = false;
Boy boys[NO_OF_BOYS];
Girl girls[NO_OF_GIRLS];
Couple couples[NO_OF_GIRLS];
// The file List_of_Boys.txt contains the list of randomly generated boys which is read and stored in the array.
ifstream read_boys_list  ("List_of_boys.txt");
if (read_boys_list.is_open())
{
	while(read_boys_list>> boys[i].name>>boys[i].attractiveness>>boys[i].budget>>boys[i].intelligence_level>>boys[i].min_attraction_requirement>>boys[i].type>>boys[i].committed)
	{
		i++;
	}
	read_boys_list.close();

}
i=0;

// The file List_of_Girls.txt contains the list of randomly generated girls which is read and stored in the array.
ifstream read_girls_list ("List_of_Girls.txt");

if (read_girls_list.is_open())
{
	cout <<"It opens\n";
	while(read_girls_list>> girls[i].name>>girls[i].attractiveness>>girls[i].maintainance_budget>>girls[i].intelligence_level>>girls[i].criterion>>girls[i].type>>girls[i].committed)
	{
		i++;

	}
	read_girls_list.close();
}

/* After reading the required amount of boys and girls, this loop proceeds with the formation of couples */
for(i=0;i<NO_OF_GIRLS;i++)
{
	for(j=0;j<NO_OF_BOYS;j++)
	{
		/*It takes into account the various criterions of girls and boys , like their attractiveness and budget and based on them assign them to each other */
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
		cout << "Couple" <<i<<" formed  : "<<boys[selectIndex].name<<" entered in a relationship with  "<<girls[i].name<<" "<<endl;
	}
	selectIndex = -1;

}

ofstream couples_list("List_of_Couples.txt");
//The Log.txt file maintains the log of all the events and transactions that take place including forming and break up of couples and gift transactions.
//It is a static file and maintains an over all log.
ofstream log_file("Log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
time_t Now = time(0);
char * ct = ctime(&Now);
for(i=0;i<couple_count;i++)
{
	couples_list << couples[i].boy.name<<" "<<couples[i].boy.attractiveness<<" "<<couples[i].boy.budget<<" "<<couples[i].boy.intelligence_level<<" "<<couples[i].boy.min_attraction_requirement<<" "<<couples[i].boy.type<<" "<<couples[i].boy.committed<<" "<<couples[i].girl.name<<" "<<couples[i].girl.attractiveness<<" "<<couples[i].girl.maintainance_budget<<" "<<couples[i].girl.intelligence_level<<" "<<couples[i].girl.criterion<<" "<<couples[i].girl.type<<" "<<couples[i].girl.committed<<endl;
	log_file << ct <<"Couple formed: "<<couples[i].boy.name<<" entered in a relationship with " <<couples[i].girl.name<<endl;
}
couples_list.close();
log_file.close();
}

//This function facilitates the transaction of various gifts which the boys in the couple gift to their girlfriends.
void MakeCouples::giveGifts()
{
	int i=0,j,couple_count, minGiftIndex=0,moneySpent = 0,moneyLeft,maxGiftIndex=0;
	bool luxury_gift = false;
	Couple  couples[100];

	Gift gifts[200];
	//Couple list file is opened to accumulate all the couples in an array.
	ifstream couples_file ("List_of_Couples.txt");
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
	//List of gifts file is opened to accumulate all the gifts in an array
	ifstream gifts_file ("List_of_Gifts.txt");
	if(gifts_file.is_open())
	{
		while(gifts_file >> gifts[i].price>>gifts[i].value>>gifts[i].type>>gifts[i].luxury_rating>>gifts[i].difficulty>>gifts[i].utility_value>>gifts[i].utility_class>>gifts[i].used)
		{
			// cout << gifts[i].price<<" "<<gifts[i].value<<" "<<gifts[i].type<<" "<<gifts[i].luxury_rating<<" "<<gifts[i].difficulty<<" "<<gifts[i].utility_value<<" "<<gifts[i].utility_class<<" "<<gifts[i].used<<endl;
			i++;
		}
	}
	int total_cost[200] = {0};
	int total_value[200] = {0};
	ofstream gift_transaction ("List_of_Gifts_Given.txt");
	ofstream log_file("Log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	//suitable gifts are given by boys to the girls satisfying the restraints set upon by the boy type and 
	for(i=0;i<couple_count;i++)
	{
		cout <<"\n\n";
		moneySpent = 0;
		moneyLeft = couples[i].boy.budget;
		luxury_gift = false;
		if(i>=1)
		{
			for(j=0;j<200;j++)
			{
				if(gifts[j].used==0)
				{
					minGiftIndex = j;
					break;
				}
			}
		}
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
			time_t Now = time(0);
			char * ct = ctime(&Now);
			if(couples[i].boy.type == MISER)
			{
				if(gifts[j].used == 1 || gifts[minGiftIndex].price>couples[i].boy.budget || gifts[minGiftIndex].price > moneyLeft || moneySpent > couples[i].girl.maintainance_budget)
					continue;
				else
				{
					if(gifts[minGiftIndex].used == 0)
					{
						gifts[minGiftIndex].used = 1;
						moneySpent += gifts[minGiftIndex].price;
						moneyLeft -= gifts[minGiftIndex].price;
						total_cost[i]+= gifts[minGiftIndex].price;
						total_value[i]+=gifts[minGiftIndex].value;
						cout<< "Couple "<<i<<": Gift of price "<<gifts[minGiftIndex].price<<" and value "<<gifts[minGiftIndex].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
						gift_transaction<< ct<<"Couple "<<i<<": Gift of price "<<gifts[minGiftIndex].price<<" and value "<<gifts[minGiftIndex].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
						log_file<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
						
					}

				}

			}
			else if(couples[i].boy.type == GENEROUS)
			{
				if(gifts[j].used == 1 || gifts[j].price>couples[i].boy.budget ||gifts[minGiftIndex].price > moneyLeft || moneySpent >= couples[i].girl.maintainance_budget)
					continue;
				else
				{
					gifts[j].used = 1;
					moneySpent += gifts[j].price;
					moneyLeft -= gifts[j].price;
					total_cost[i]+= gifts[j].price;
					total_value[i]+=gifts[j].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
					gift_transaction<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
					log_file<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
				}
			}
			else
			{
				if(gifts[j].used == 1 || gifts[minGiftIndex].price>couples[i].boy.budget || gifts[minGiftIndex].price > moneyLeft || moneySpent > couples[i].girl.maintainance_budget)
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
						total_value[i]+=gifts[j].value;
						cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
						gift_transaction<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
						log_file<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
					}
					else
					{
					gifts[j].used = 1;
					moneySpent += gifts[j].price;
					moneyLeft -= gifts[j].price;
					total_cost[i]+= gifts[j].price;
					total_value[i]+=gifts[j].value;
					cout<< "Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
					gift_transaction<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
					log_file<< ct<<"Couple "<<i<<": Gift of price "<<gifts[j].price<<" and value "<<gifts[i].value<<" was given by "<<couples[i].boy.name<<" to "<<couples[i].girl.name<<endl<<endl;
					}

				}
			}
		}
	}
	for(i=0;i<couple_count;i++)
	{
		couples[i].girl.getHappiness(total_cost[i], total_value[i]);
		couples[i].boy.getHappiness(couples[i].girl, total_cost[i]);
		couples[i].happiness = couples[i].boy.happiness+couples[i].girl.happiness;
		couples[i].find_compatibility();

	}
	int k;
	cout<< "Enter the value of K\n";
	cin >> k;
	if(k<=couple_count){
	//These helper functions help in calculating the k most happy and k most compatible couples
	Couple::k_happy(couples,couple_count,k);	
	Couple::k_compatible(couples,couple_count,k);
	}
	else
	{
		cout<<"The value of k entered by you exceeds the number of couples"<<endl;
	}
	log_file.close();
}