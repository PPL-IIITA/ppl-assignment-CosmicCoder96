#include <iostream>
#include <fstream>
#include <time.h>
#include "Gift.h"
#define NO_OF_GIFTS 200
using namespace std;

int main()
{
	srand(time(NULL));
	Gift gifts[NO_OF_GIFTS];
	for(i=0;i<NO_OF_GIFTS;i++)
	{
		gifts[i].price = rand()%1000;
		gifts[i].value = rand()%1000;
		gifts[i].type = rand()%3;
	}
}