#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Boy.h"
#define NO_OF_BOYS 100
using namespace std;

int main()
{
srand(time(NULL));
Boy boys[NO_OF_BOYS];
int i, nameLength,j;
for(i=0;i<NO_OF_BOYS;i++)
{
	for(j=0;j<MAX_NAME_LENGTH-1;j++)
	{
		boys[i].name[j] = rand()%26+97;
	}
	boys[i].name[j]='\0';
	boys[i].attractiveness = rand()%10;
	boys[i].budget = rand()%5000;
	boys[i].intelligence_level = rand()%100;
	boys[i].min_attraction_requirement = rand()%10;
	boys[i].type = rand()%3;
	boys[i].committed = 0;

}
ofstream file ("List_of_boys.txt");
// fd = fopen(, "w");
if(file.is_open()){
for(i=0;i<NO_OF_BOYS;i++)
{
	file<<boys[i].name<<" "<<boys[i].attractiveness<<" "<<boys[i].budget<<" "<<boys[i].intelligence_level<<" "<<boys[i].min_attraction_requirement<<" "<<boys[i].type<<" "<<boys[i].committed<<endl;
	// file<<boys[i].name<<" "<<boys[i].attractiveness<<" "<<boys[i].budget<<" "<<boys[i].intelligence_level<<" "<boys[i].type<<"\n";
}
file.close();
}
}
