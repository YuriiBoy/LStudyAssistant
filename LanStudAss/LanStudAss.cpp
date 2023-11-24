#include "Header.h"
#include "Menu.h"
#include "TestMenu.h"
#include "ShortListManager.h"

int main()
{
	std::string taskName = "Language Study Assistant";
	std::vector<std::string> menuList = {
		"Create shortlist for N words",
		"Show shortlist",
		"Delete shortlist",
		"Show all vocabular",
		"Correct word translation in the vocabulary",
		"Look for word tranlation in the vocabulary",
		"Test",
		"Exit"
	};

	std::vector<std::string> testMenu = {
		"Take the short list test",
		"Take the common test",
		"Show previous results",
		"Delete previous resuilts",
		"Exit"
	};

	std::unique_ptr<Menu> m(new Menu(taskName, menuList));
	std::unique_ptr<TestMenu> t(new TestMenu(testMenu));
	auto sl = std::make_unique<ShortListManager>();
	sl->loadData();

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
			sl->addData();
			break;
		case 2:
			sl->displayData();
			break;
		case 3:
			sl->deleteData();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
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
				case 4:
					break;
				case 5: test = false;
					break;
				default:
					std::cout << "\n Wrong choice";
					Sleep(1000);
					break;
				}
			} while (test);
			break;
		case 8: stop = true;
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
