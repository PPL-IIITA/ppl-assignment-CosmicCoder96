#include <iostream>
#include <cmath>
#include "Girl.h"
#define CHOOSY 0
#define NORMAL 1
#define DESPERATE 2
using namespace std;

void Girl::getHappiness(int total_gifts, int total_gift_value)
{
	if(type == CHOOSY)
	{
		// happiness = log(total_gifts - maintainance_budget);
		happiness = 0;
	}
	else if(type == NORMAL)
	{
		happiness = total_gifts-(maintainance_budget + total_gift_value);
	}
	else
	{
		happiness = (int)exp((total_gifts - maintainance_budget)%5);
	}
}