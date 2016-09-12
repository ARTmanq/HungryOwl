#include "Animals.h"

Animal::Animal(): HP(0)
{}

Animal::Animal(unsigned int hp): HP(hp)
{}

Animal::~Animal()
{}

void Animal::injure()
{}

void Animal::move() const
{}

Owl::Owl(): Animal(3)
{}

Owl::~Owl()
{}

void Owl::move(unsigned int x, unsigned int y) const
{}

void Owl::attack()
{}

Mouse::Mouse(): Animal(1)
{}

Mouse::~Mouse()
{}

void Mouse::move() const
{}

Cat::Cat(): Animal(2)
{}

Cat::~Cat()
{}

void Cat::move() const
{}
