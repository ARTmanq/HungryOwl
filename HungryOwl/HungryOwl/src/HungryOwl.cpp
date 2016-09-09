#include <iostream>
#include <string>

int main() {
	std::cout << "---<<<   HUNGRY OWL   >>>---" << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << "Select:   " << std::endl;
	int menuChoice = 0;
	std::string inputBuffer;
	while(menuChoice != 1 || menuChoice != 2)
	{
		std::cin >> inputBuffer;
		try
		{
			menuChoice = std::stoi(inputBuffer);
			switch(menuChoice)
			{
			case 1:
				{
					break;
				}
			case 2:
				{
					break;
				}
			default:
				{
					std::cout << "Incorrect choice, try again:" << std::endl;
				}
			}
		}
		catch(std::invalid_argument &ia)
		{
			std::cout << "Incorrect choice, try again:" << std::endl;
		}

	}
	return 0;
}
