#pragma once
#ifndef _ANIMALS_H_
#define _ANIMALS_H_
#include <iostream>

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

#endif
