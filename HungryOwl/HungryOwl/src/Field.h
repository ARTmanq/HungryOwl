#pragma once
#ifndef _FIELD_H_
#define _FIELD_H_
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
		Animal();
		Animal(unsigned int);
		virtual ~Animal();
		virtual void injure();
		virtual void move() const;
	private:
		unsigned int HP;
};

class Owl : public Animal
{
	public:
		Owl();
		virtual ~Owl();
		void move(unsigned int, unsigned int) const;
		void attack();
};

class Mouse : public Animal
{
	public:
		Mouse();
		virtual ~Mouse();
		void move() const;
};

class Cat: public Animal
{
	public:
		Cat();
		virtual ~Cat();
		void move() const;
};

class Cell
{
	public:
		Cell();
		~Cell();
		bool isFree() const;
		void setAnimal(Animal*);
		void show() const;
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
		bool checkCell(unsigned int, unsigned int);
		void addAnimal(unsigned int, unsigned int, Animal*);
	private:
		std::vector<std::vector<Cell> > field;
		unsigned int size;
		unsigned int amountOfMices;
		unsigned int amountOfCats;
};

#endif