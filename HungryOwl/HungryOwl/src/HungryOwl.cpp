#include <iostream>
#include <string>

int getnum();

int main()
{
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
