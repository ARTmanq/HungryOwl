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
	unsigned int i, j;
	std::minstd_rand0 gen;
	for(i = 0; i < s; ++i)
	{
		std::vector<Cell> currentLine;
		for(j = 0; j < s; ++j)
		{
			Cell currentCell;
			unsigned int random = gen() % 100;
			if(random >= 50)
			{


			}
		}
	}
}

Field::~Field()
{

}
