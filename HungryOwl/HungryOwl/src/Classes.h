#include <iostream>
#include <vector>
#include <random>
#include <typeinfo>

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
		Animal(unsigned int hp): HP(hp){};
		virtual ~Animal(){};
		virtual void injure(){};
		virtual void move() const{};
	private:
		unsigned int HP;
};

class Cell
{
	public:
		Cell();
		~Cell(){};
		bool isFree() const;
		void setAnimal(Animal*);
		void show() const;
	private:
		unsigned int detectedAnimals;
		Colors cellColor;
		Animal *animal;
};

class Owl : public Animal
{
	public:
		Owl(): Animal(3){};
		virtual ~Owl(){};
		void move(unsigned int, unsigned int) const{};
		void attack(Cell&) {};
};

class Mouse : public Animal
{
	public:
		Mouse(): Animal(1) {};
		virtual ~Mouse(){};
		void move() const {};
};

class Cat: public Animal
{
	public:
		Cat(): Animal(2){};
		virtual ~Cat(){};
		void move() const {};
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
		bool checkCell(unsigned int, unsigned int);
		void addAnimal(unsigned int, unsigned int, Animal*);
	private:
		std::vector<std::vector<Cell> > field;
		unsigned int size;
		unsigned int amountOfMices;
		unsigned int amountOfCats;
};