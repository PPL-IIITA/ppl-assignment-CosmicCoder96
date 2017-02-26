#include <iostream>
#include "Boy.h"
#include "Girl.h"
using namespace std;

void Boy::getHappiness(Girl& girl_friend, int total_gifts)
{
	if(type == MISER)
	{
		happiness = budget - total_gifts;
		// happiness = 0;

	}
	else if (type == GENEROUS)
	{
		happiness = girl_friend.happiness;
		//happiness = 0;
	}

	else
	{
		happiness = girl_friend.intelligence_level;
	}
}