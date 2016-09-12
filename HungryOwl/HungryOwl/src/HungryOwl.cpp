#include <iostream>
#include <string>
#include "Field.h"
#include "Animals.h"

int getnum();
void setDifficulty(Field&);
void game(Field&, Owl&);

int main()
{
	Field field;
	Owl owl;
	std::cout << "---<<<   HUNGRY OWL   >>>---" << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << "Select:   " << std::endl;
	int menuChoice = 0;
	while(menuChoice != 1 || menuChoice != 2)
	{
		menuChoice = getnum();
		switch(menuChoice)
		{
			case 1:
				{
					setDifficulty(field);
					game(field, owl);
					break;
				}
			case 2:
				{
					return 0;
					break;
				}
			default:
				{
					std::cout << "Wrong choice, try again:" << std::endl;
				}
		}
	}
	return 0;
}

int getnum()
{
	std::string inputBuffer;
	int result = 0;
	bool correctInteger = false;
	while(!correctInteger)
	{
		std::cin >> inputBuffer;
		try
		{
			result = std::stoi(inputBuffer);
			correctInteger = true;
		}
		catch(std::invalid_argument &ia)
		{
			std::cout << "Wrong integer, try again:" << std::endl;
		}
	}
	return result;
}

void setDifficulty(Field& field)
{
	std::cout << "   Select difficulty:" << std::endl;
	std::cout << "1. Easy" << std::endl;
	std::cout << "2. Medium" << std::endl;
	std::cout << "3. Hard" << std::endl;
	int menuChoice;
	while(menuChoice < 1 || menuChoice > 3)
	{
		menuChoice = getnum();
		switch(menuChoice)
		{
			case 1:
				{
					try
					{
						field.set(10, 8, 8);
					}
					catch(const char* errormsg)
					{
						std::cout << errormsg << std::endl;
					}
					break;
				}
			case 2:
				{
					try
					{
						field.set(15, 12, 12);
					}
					catch(const char* errormsg)
					{
						std::cout << errormsg << std::endl;
					}
					break;
				}
			case 3:
				{
					try
					{
						field.set(20, 16, 16);
					}
					catch(const char* errormsg)
					{
						std::cout << errormsg << std::endl;
					}
					break;
				}
			default:
				{
					std::cout << "Wrong choice, try again:" << std::endl;
				}
		}
	}
}

void game(Field& field, Owl& owl)
{
	field.show();
}
