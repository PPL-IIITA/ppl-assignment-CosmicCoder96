#include <iostream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
using namespace std;


//The find_compatibility() function calculates the comaptibility of a particular couple by using the formula as given.
void Couple::find_compatibility()
{
	compatibility = (boy.budget - girl.maintainance_budget) + abs(boy.attractiveness - girl.attractiveness) + abs(girl.intelligence_level - boy.intelligence_level);
}

//The k_happy function accepts an array of couples and the value entered by the user,k
void Couple:: k_happy(Couple *couples,int n, int k)
{
	cout<<"\nThe "<<k<<" most happy couples with their happiness are \n\n";
	int done[200] = {0};
	int maxHappyIndex = 0,i,j; //The function finds out the k-happiest couples and then prints them in order.
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(done[j]==0)
			{
				maxHappyIndex = j;
				break;
			}
		}
		for(j = 0;j<n;j++)
		{
			if(done[j] == 0 && couples[j].happiness > couples[maxHappyIndex].happiness)
			{
				maxHappyIndex = j;

			}
		}
		cout<<couples[maxHappyIndex].boy.name <<" "<<couples[maxHappyIndex].girl.name <<" "<<couples[maxHappyIndex].happiness<<endl<<endl;
		done[maxHappyIndex] = 1;
	}
}

//The k_compatible function accepts an array of couples and the value entered by the user,k
void Couple::k_compatible(Couple *couples, int n, int k)
{
	cout<<"\nThe "<<k<<" most compatible couples with their compatibility are \n\n";
	int done[200] = {0};
	int  maxCompatibleIndex = 0,i,j; //The function finds out the k most compatible couples and then prints them in order.
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(done[j]==0)
			{
				maxCompatibleIndex = j;
				break;
			}
		}
		for(j = 0;j<n;j++)
		{
			if(done[j] == 0 && couples[j].compatibility > couples[maxCompatibleIndex].compatibility)
			{
				maxCompatibleIndex = j;

			}
		}
		cout<<couples[maxCompatibleIndex].boy.name <<" "<<couples[maxCompatibleIndex].girl.name <<" "<<couples[maxCompatibleIndex].compatibility<<endl<<endl;
		done[maxCompatibleIndex] = 1;
	}
}
