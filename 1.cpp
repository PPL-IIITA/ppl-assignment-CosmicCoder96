#include <iostream>
#include <fstream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "MakeCouples.h"
#define NO_OF_BOYS 100
#define NO_OF_GIRLS 50
#define MOST_ATTRACTIVE 0
#define MOST_RICH 1
#define MOST_INTELLIGENT 2
using namespace std;
int main ()
{ 
	MakeCouples generator;
	generator.generateCouples();
}