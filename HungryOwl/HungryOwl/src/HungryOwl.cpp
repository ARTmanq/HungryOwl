#include <iostream>

int main() {
	std::cout << "---<<<   HUNGRY OWL   >>>---" << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << "Select:   " << std::endl;
	int menuChoice = 0;
	while(menuChoice != 1 || menuChoice != 2)
	{
		std::cin >> menuChoice;
		switch(menuChoice)
		{
		case 1:
			{
				int a;
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
	return 0;
}
