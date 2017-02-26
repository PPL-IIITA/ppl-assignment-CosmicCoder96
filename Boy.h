#ifndef BOY_H_
#define BOY_H_
#define MAX_NAME_LENGTH 7
#define MISER 0
#define GENEROUS 1
#define GEEK 2
#include "Girl.h"

class Boy{
public:
	char name[MAX_NAME_LENGTH];
	int attractiveness;
	int budget;
	int intelligence_level;
	int min_attraction_requirement;
	int type;
	int committed;
	int happiness;
	void getHappiness(Girl& girl_friend, int total_gifts);
};

#endif


