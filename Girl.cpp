#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Girl.h"
#define CHOOSY 0
#define NORMAL 1
#define DESPERATE 2
using namespace std;

//!< The function getHappiness in the Girl class is used to calculate the happiness of a girl with total gift cost and total gift_value as parameters.
void Girl::getHappiness(int total_gifts, int total_gift_value)
{
	if(type == CHOOSY) //!< These if else conditions ensure that happiness of the girls is calculated based on the type of girl i.e. CHOOSY, NORMAL or DESPERATE
	{
	     happiness = log(abs(total_gifts - maintainance_budget));
	}
	else if(type == NORMAL)
	{
		happiness = (total_gifts-maintainance_budget) + total_gift_value;
	}
	else
	{
		happiness = (int)exp((total_gifts - maintainance_budget)%5);
	}
}