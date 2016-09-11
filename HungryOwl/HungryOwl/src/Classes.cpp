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
	for(i = 0; i < s; ++i)
	{
		std::vector<Cell> currentLine;
		for(j = 0; j < s; ++j)
		{
			Cell cell;
			currentLine.push_back(cell);
		}
		field.push_back(currentLine);
	}
	for(i = 0; i < AoM; ++i)
	{
		x = gen() % s;
		y = gen() % s;
		if(checkCell(x, y))
		{
			Mouse mouse;
			addAnimal(x, y, &mouse);
		}
	}
	for(j = 0; j < AoC; ++j)
	{
		x = gen() % s;
		y = gen() % s;
		if(checkCell(x, y))
		{
			Cat cat;
			addAnimal(x, y, &cat);
		}
	}
}

Field::~Field()
{}

bool Field::checkCell(unsigned int x, unsigned int y)
{
	if(field[x][y].isFree())
		return true;
	else
		return false;
}

void Field::addAnimal(unsigned int x, unsigned int y, Animal* animal)
{
	field[x][y].setAnimal(animal);
	animal = nullptr;
}

Cell::Cell(): detectedAnimals(0), cellColor(Colors::green), animal(nullptr)
{}

bool Cell::isFree() const
{
	if(animal == nullptr)
		return true;
	else
		return false;
}

void Cell::setAnimal(Animal* creature)
{
	animal = new Animal(*creature);
	creature = nullptr;
}
