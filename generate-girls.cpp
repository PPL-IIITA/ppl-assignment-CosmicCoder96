#include <iostream>
#include <fstream>
#include <time.h>
#include "Girl.h"
#define NO_OF_GIRLS 50
using namespace std;

int main()
{
srand(time(NULL));
Girl girls[NO_OF_GIRLS];
int i, nameLength,j;
for(i=0;i<NO_OF_GIRLS;i++)
{
	for(j=0;j<MAX_NAME_LENGTH-1;j++)
	{
		girls[i].name[j] = rand()%26+97;
	}
	girls[i].name[j]='\0';
	girls[i].attractiveness = rand()%10;
	girls[i].maintainance_budget = rand()%5000;
	girls[i].intelligence_level = rand()%100;
	girls[i].criterion = rand()%3;
	girls[i].type = rand()%3;
	girls[i].committed = 0;

}
ofstream file ("List_of_Girls.txt");
// fd = fopen(, "w");
if(file.is_open()){
for(i=0;i<NO_OF_GIRLS;i++)
{
	file<<girls[i].name<<" "<<girls[i].attractiveness<<" "<<girls[i].maintainance_budget<<" "<<girls[i].intelligence_level<<" "<<girls[i].criterion<<" "<<girls[i].type<<" "<<girls[i].committed<<endl;
}
file.close();
}
}
