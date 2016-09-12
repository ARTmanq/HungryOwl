#pragma once
#ifndef _FIELD_H_
#define _FIELD_H_
#include <iostream>
#include <vector>
#include <random>
#include <typeinfo>
#include "Animals.h"

enum class Colors 
{
	green,
	yellow,
	red,
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