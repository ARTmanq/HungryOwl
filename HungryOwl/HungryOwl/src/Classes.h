#include <iostream>
#include <vector>

enum class Colors 
{
	green,
	yellow,
	red,
};

class Cell
{
	public:
	
	private:
		int detectedAnimals;
		Colors cellColor;
};

class Field
{
	public:
		Field();
		Field(const Field&);
		Field(Field&&);
		Field & operator = (const Field&);
		Field & operator = (Field&&);
		~Field();
		void show() const;
		void refresh();
	private:
		std::vector<Cell> field;
};

class Animal
{
};

class Owl : public Animal
{
};

class Mouse : public Animal
{
};

class Cat: public Animal
{
};