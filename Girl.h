#ifndef GIRL_H_
#define GIRL_H_
#define MAX_NAME_LENGTH 7
class Girl {
public:
	char name[MAX_NAME_LENGTH];
	int attractiveness;
	int maintainance_budget;
	int intelligence_level;
	int criterion;
	int type;
	int committed;
	int happiness;
	void getHappiness(int total_gifts, int total_gift_value);
	
};
#endif