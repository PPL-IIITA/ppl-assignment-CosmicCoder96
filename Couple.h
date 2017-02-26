#ifndef COUPLE_H_
#define COUPLE_H_
#define MAX_NAME_LENGTH 7
class Couple{
public:
	Boy boy;
	Girl girl;
	int happiness;
	int compatibility;	
	void find_compatibility();
	static void k_happy(Couple *couples,int n, int k);
	static void k_compatible(Couple *couples, int n, int k);
};

#endif