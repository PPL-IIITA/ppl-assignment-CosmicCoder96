#include <iostream>
#include <fstream>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "Gift.h"
#include "MakeCouples.h"
using namespace std;
int main ()
{ 
	MakeCouples generator;
	generator.generateCouples();
	generator.giveGifts();

}