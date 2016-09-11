#include <iostream>
#include <vector>

enum class Colors 
{
	green,
	yellow,
	red,
};

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		virtual void injure();
		virtual void move() const;
	private:
		unsigned int HP;
};

class Owl : public Animal
{
	public:
		void move() const;
};

class Mouse : public Animal
{
	public:
		void move() const;
};

class Cat: public Animal
{
	public:
		void move() const;
};

class Cell
{
	public:
		Cell();
		~Cell(){};
	private:
		unsigned int detectedAnimals;
		Colors cellColor;
		Animal *animal;
};

class Field
{
	public:
		Field();
		~Field();
		void set(unsigned int, unsigned int, unsigned int); 
		void show() const;
		void refresh();
	private:
		std::vector<Cell> field;
		unsigned int size;
		unsigned int amountOfMices;
		unsigned int amountOfCats;
};