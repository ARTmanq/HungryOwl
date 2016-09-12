#include "Field.h"



Cell::Cell(): detectedAnimals(0), cellColor(Colors::green), animal(nullptr)
{}

Cell::~Cell()
{
	delete animal;
}

bool Cell::isFree() const
{
	if(animal == nullptr)
		return true;
	else
		return false;
}

void Cell::setAnimal(Animal* creature)
{
	animal = creature;
	creature = nullptr;
}

void Cell::show() const
{
	if(animal == nullptr)
	{
		std::cout << ". ";
	}
	else
	{
		std::cout << typeid(*animal).name()[1] << ' ';
	}
}



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
	for(i = 0; i < size; ++i)
	{
		std::vector<Cell> currentLine;
		for(j = 0; j < size; ++j)
		{
			Cell cell;
			currentLine.push_back(cell);
		}
		field.push_back(currentLine);
	}
	for(i = 0; i < amountOfMices; ++i)
	{
		x = gen() % size;
		y = gen() % size;
		if(checkCell(x, y))
		{
			Mouse* mouse = new Mouse;
			addAnimal(x, y, mouse);
		}
	}
	for(j = 0; j < amountOfCats; ++j)
	{
		x = gen() % size;
		y = gen() % size;
		if(checkCell(x, y))
		{
			Cat* cat = new Cat;
			addAnimal(x, y, cat);
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

void Field::show() const
{
	unsigned int i, j;
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			field[i][j].show();
		}
		std::cout << std::endl;
	}
}

