#include "Header.h"
#include "TestManager.h"

void TestManager::loadShortListData()
{
	std::ifstream fin;
	fin.open("ShortListData.txt");
	int id = 0;
	std::string key;
	std::string val;
	int quest = 0;
	int ransw = 0;
	int percent = 0; 

	while (!fin.eof()) {
		id++;
		std::getline(fin, key);
		std::getline(fin, val);
		Test tests(id, key, val, quest, ransw, percent);
		test.push_back(tests);
	}
	test.pop_back();
	fin.close();
}

void TestManager::loadData()
{

	std::ifstream fin;
	fin.open("Data.txt");
	int id = 0;
	std::string key;
	std::string val;
	int quest = 0;
	int ransw = 0;
	int percent = 0;

	while (!fin.eof()) {
		id++;
		std::getline(fin, key);
		std::getline(fin, val);
		Test tests(id, key, val, quest, ransw, percent);
		testDict.push_back(tests);
	}
	test.pop_back();
	fin.close();
}

void TestManager::display() const
{
	for (int i = 0; i < test.size(); i++) {
		test[i].display();
	}
}

void TestManager::shortListTest()
{
	system("cls");
	std::cout << std::endl;
	if (test.empty()) {
		std::cout << "\n Short list is empty"; 
	}
	else {
		int N = test.size();
		std::string trans;
		int countR = 0;
		int countW = 0;
		std::cin.ignore();

		for (int i = 0; i < N; i++) {
			std::cout << std::endl;
			std::cout << test[i].getKey();
			std::cout  << " - Write the translation: ";
			std::getline(std::cin, trans);

			if (test[i].getVal() == trans) {
				std::cout << "Right\n";
				countR++;
				system("cls");
			}
			else if (test[i].getVal() != trans) {
				std::cout << " Wrong, the wright translation is - " << test[i].getVal() << std::endl;;
				countW++;
				system("cls");
			}
		}
		std::cout << "\n Test had " << N << " questions\n";
		std::cout << " - " << countR << " right answers\n";
		std::cout << " - " << countW << " wrong answers\n";
		std::cout << " - " << 100 * countR / N << " % of right answers\n";
		display();
	}
}

void TestManager::commonTest()
{
	system("cls");
	std::cout << std::endl;
	if (testDict.size() < 20) {
		std::cout << "\n Dictionary is empty or short";
	}
	else {
		int N = testDict.size();
		std::string trans;
		int countR = 0;
		int countW = 0;
		int k;
		srand(time(0));
		k = rand() % (N - 19);
		std::cin.ignore();

		for (int i = k; i < k + 20; i++) {
			std::cout << std::endl;
			std::cout << testDict[i].getKey();
			std::cout << " - Write the translation: ";
			std::getline(std::cin, trans);

			if (testDict[i].getVal() == trans) {
				std::cout << "Right\n";
				countR++;
				Sleep(1000);
				system("cls");
			}
			else if (testDict[i].getVal() != trans) {
				std::cout << " Wrong, shoul be  - \n";
				std::cout << "============================\n";
				std::cout << " " << testDict[i].getKey() << " - " << testDict[i].getVal() << std::endl;;
				countW++;
				Sleep(2000);
				system("cls");
			}
		}

		std::cout << "\n Test had " << " 20 questions\n";
		std::cout << " - " << countR << " right answers\n";
		std::cout << " - " << countW << " wrong answers\n";
		std::cout << " - " << 100 * countR / N << " % of right answers\n";
		for (int i = k; i < k + 20; i++) {
			std::cout << i - k + 1 << " " << testDict[i].getKey() << " - " << testDict[i].getVal() << std::endl;
		}
	}
}


