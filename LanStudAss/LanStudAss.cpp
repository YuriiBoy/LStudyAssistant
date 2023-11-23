#include "Header.h"
#include "Menu.h"
#include "TestMenu.h"

int main()
{
	std::string taskName = "Language Study Assistant";
	std::vector<std::string> menuList = {
		"Create shortlist",
		"Show shortlist",
		"Delete shortlist",
		"Correct word translation in the dictionary",
		"Look for word tranlation in the dictionary",
		"Test",
		"Exit"
	};

	std::vector<std::string> testMenu = {
		"Take the test",
		"Show previous results",
		"Delete previous resuilts",
		"Exit"
	};

	std::unique_ptr<Menu> m(new Menu(taskName, menuList));
	std::unique_ptr<TestMenu> t(new TestMenu(testMenu));

	bool stop = false;
	bool test = true;

	do {
		system("cls");
		m->displayTaskName();
		m->displayListMenu();
		int choice = m->getChoice();
		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			do {
				system("cls");
				t->displayTestMenu();
				int var = t->getChoice();
				switch (var)
				{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4: test = false;
					break;
				default:
					std::cout << "\n Wrong choice";
					Sleep(1000);
					break;
				}
			} while (test);
			break;
		case 7: stop = true;
			break;
		default: 
			std::cout << "\n Wrong choice";
			break;
		}
		if (stop) {
			break;
		}

	} while (m->allowContinue());
	
   

}
