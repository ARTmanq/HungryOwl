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
	unsigned int i, j, x, y;
	std::minstd_rand0 gen;
	for(i = 0; i < AoM; ++i)
	{
		x = gen() % s;
		y = gen() % s;
		if(!checkCell(x, y))
		{
			Mouse mouse;
			addAnimal(x, y, &mouse);
		}
	}
	for(j = 0; j < AoC; ++j)
	{
		x = gen() % s;
		y = gen() % s;
		if(!checkCell(x, y))
		{
			Cat cat;
			addAnimal(x, y, &cat);
		}
	}
}

Field::~Field()
{

}
