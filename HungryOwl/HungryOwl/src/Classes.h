#include <iostream>
#include <vector>
#include <random>

enum class Colors 
{
	green,
	yellow,
	red,
};

class Animal
{
	public:
		Animal(){};
		virtual ~Animal(){};
		virtual void injure(){};
		virtual void move() const{};
	private:
		unsigned int HP;
};

class Cell
{
	public:
		Cell(){};
		~Cell(){};
		void addAnimal(Animal*) {};
	private:
		unsigned int detectedAnimals;
		Colors cellColor;
		Animal *animal;
};

class Owl : public Animal
{
	public:
		Owl(): Animal(){};
		virtual ~Owl(){};
		void move(unsigned int, unsigned int) const{};
		void attack(Cell&) {};
};

class Mouse : public Animal
{
	public:
		Mouse(): Animal() {};
		virtual ~Mouse(){};
		void move() const;
};

class Cat: public Animal
{
	public:
		Cat(){};
		virtual ~Cat(){};
		void move() const;
};



class Field
{
	public:
		Field();
		~Field();
		void set(unsigned int, unsigned int, unsigned int); 
		void show() const;
		void moveAnimals() {};
		void discoverCell(unsigned int, unsigned int) {};
		Cell& getCell(unsigned int, unsigned int) {};
	private:
		std::vector<std::vector<Cell> > field;
		unsigned int size;
		unsigned int amountOfMices;
		unsigned int amountOfCats;
};