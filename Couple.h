#ifndef COUPLE_H_
#define COUPLE_H_
#define MAX_NAME_LENGTH 7

class Couple{
public:
	Boy boy;
	Girl girl;
	int happiness;
	int compatibility;
	void make_couples(Boy boy, Girl girl);
};

#endif