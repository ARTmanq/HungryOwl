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
			try
			{
				currentLine.push_back(cell);
			}
			catch(std::bad_alloc &ba)
			{
				throw("!!!Not enough memory!!!");
			}
		}
		try
		{
			field.push_back(currentLine);
		}
		catch(std::bad_alloc &ba)
		{
			throw("!!!Not enough memory!!!");
		}
	}
	for(i = 0; i < amountOfMices; ++i)
	{
		x = gen() % size;
		y = gen() % size;
		if(checkCell(x, y))
		{
			try
			{
				Mouse* mouse = new Mouse;
				addAnimal(x, y, mouse);
			}
			catch(std::bad_alloc &ba)
			{
				throw("!!!Not enough memory!!!");
			}
		}
	}
	for(j = 0; j < amountOfCats; ++j)
	{
		x = gen() % size;
		y = gen() % size;
		if(checkCell(x, y))
		{
			try
			{
				Cat* cat = new Cat;
				addAnimal(x, y, cat);
			}
			catch(std::bad_alloc &ba)
			{
				throw("!!!Not enough memory!!!");
			}
		}
	}
}

Field::~Field()
{}

bool Field::checkCell(unsigned int x, unsigned int y)
{
	try
	{
		if(field[x][y].isFree())
			return true;
		else
			return false;
	}
	catch(std::out_of_range &oor)
	{
		throw("!!!Out of range in function Field.checkCell!!!");
	}
}

void Field::addAnimal(unsigned int x, unsigned int y, Animal* animal)
{
	try
	{
		field[x][y].setAnimal(animal);
	}
	catch(std::out_of_range &oor)
	{
		throw("!!!Out of range in function Field.addAnimal!!!");
	}
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

