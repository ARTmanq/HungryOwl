#include <iostream>
#include <string>
#include "Classes.h"

int getnum();
void setDifficulty(Field&);
void game(Field&);

int main()
{
	Field field;
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
					game(field);
					break;
				}
			case 2:
				{
					return 0;
					break;
				}
			default:
				{
					std::cout << "Incorrect choice, try again:" << std::endl;
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
			std::cout << "Incorrect integer, try again:" << std::endl;
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
					field.set(10, 8, 8);
					break;
				}
			case 2:
				{
					field.set(15, 12, 12);
					break;
				}
			case 3:
				{
					field.set(20, 16, 16);
					break;
				}
			default:
				{
					std::cout << "Incorrect choice, try again:" << std::endl;
				}
		}
	}
}

void game(Field& field)
{
	std::cout << "Enter coordinates:" << std::endl;
	int x = getnum(), y = getnum();
	try
	{

	}
	catch(std::invalid_argument &ia)
	{

	}
}
