#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Boy.h"
#include "Girl.h"
using namespace std;
//!< This is the class file for the Boy class. It defines it's various attributes of a boy object like attractiveness, budget, intelligence_level, and type which cam be MISER or GENEROUS OR GEEK 
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