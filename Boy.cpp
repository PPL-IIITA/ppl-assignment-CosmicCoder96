#include <iostream>
#include "Boy.h"
#include "Girl.h"
#define MISER 0
#define GENEROUS 1
#define GEEK 2
using namespace std;

void Boy::getHappiness(Girl& girl_friend, int total_gifts)
{
	if(type == MISER)
	{
		happiness = budget - total_gifts;
	}
	else if (type == GENEROUS)
	{
		happiness = girl_friend.happiness;
	}

	else
	{
		happiness = girl_friend.intelligence_level;
	}
}