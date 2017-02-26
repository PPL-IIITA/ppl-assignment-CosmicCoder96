/* This file is used to generate gifts with random prices and values and store them in 
the text file List_of_Gifts.txt */
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "Gift.h"
#define NO_OF_GIFTS 200
using namespace std;

int main()
{
	srand(time(NULL));
	Gift gifts[NO_OF_GIFTS];
	int i;
	//This for loop assigns random values to various attributes of the gift object.
	for(i=0;i<NO_OF_GIFTS;i++)
	{
		gifts[i].price = rand()%1000;
		gifts[i].value = rand()%1000;
		gifts[i].type = rand()%3;
		gifts[i].used = 0;
		if(gifts[i].type == ESSENTIAL)
		{
			gifts[i].luxury_rating = 0;
			gifts[i].utility_value = 0;
			gifts[i].utility_class = 0;
			gifts[i].difficulty = 0;
		}
		else if(gifts[i].type == LUXURY)
		{
			gifts[i].luxury_rating = rand()%10;
			gifts[i].utility_value = 0;
			gifts[i].utility_class = 0;
			gifts[i].difficulty = rand()%10;
		}
		else 
		{
			gifts[i].luxury_rating = 0;
			gifts[i].utility_value = rand()%10;
			gifts[i].utility_class = rand()%5;
			gifts[i].difficulty = 0;
		}
	}
	//The file List_of_Gifts.txt is opened and the values of various gifts are stored in it
	ofstream file ("List_of_Gifts.txt");
	for(i=0;i<NO_OF_GIFTS;i++)
	{
		file << gifts[i].price<<" "<<gifts[i].value<<" "<<gifts[i].type<<" "<<gifts[i].luxury_rating<<" "<<gifts[i].difficulty<<" "<<gifts[i].utility_value<<" "<<gifts[i].utility_class<<" "<<gifts[i].used<<endl;
	}

	file.close();
}