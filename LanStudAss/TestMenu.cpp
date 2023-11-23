#include "Header.h"
#include "TestMenu.h"

TestMenu::TestMenu(std::vector<std::string> testMenu)
	: testMenu(testMenu)
{}

void TestMenu::displayTestMenu() const
{
	std::cout << "\n\t ===========================";
	for (int i = 0; i < testMenu.size(); i++) {
		std::cout << "\n\t" << i + 1;
		std::cout << " - " << testMenu[i];
	}
	std::cout << "\n\t ===========================";
	std::cout << std::endl;
	
}

int TestMenu::getChoice() const
{
	int choice;
	std::cout << "\n Make your choice: ";
	std::cin >> choice;
	return choice;
}
