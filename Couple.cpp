#include <iostream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
using namespace std;

void Couple::find_compatibility()
{
	compatibility = (boy.budget - girl.maintainance_budget) + abs(boy.attractiveness - girl.attractiveness) + abs(girl.intelligence_level - boy.intelligence_level);
}

void Couple:: k_happy(Couple *couples,int n, int k)
{
	int done[200] = {0};
	int maxHappyIndex = 0,i,j; 
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
		cout<<couples[maxHappyIndex].boy.name <<" "<<couples[maxHappyIndex].girl.name <<" "<<couples[maxHappyIndex].happiness<<endl;
		done[maxHappyIndex] = 1;
	}
}

void Couple::k_compatible(Couple *couples, int n, int k)
{
	int done[200] = {0};
	int  maxCompatibleIndex = 0,i,j; 
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
		cout<<couples[maxCompatibleIndex].boy.name <<" "<<couples[maxCompatibleIndex].girl.name <<" "<<couples[maxCompatibleIndex].compatibility<<endl;
		done[maxCompatibleIndex] = 1;
	}
}
