#include "Classes.h"

Field::Field()
{
	size = 0;
	amountOfMices = 0;
	amountOfCats = 0;
}

void Field::set(unsigned int s, unsigned int AoM, unsigned int AoC)
{
	size = s;
	amountOfMices = AoM;
	amountOfCats = AoC;
	//vector init
}

Field::~Field()
{

}
