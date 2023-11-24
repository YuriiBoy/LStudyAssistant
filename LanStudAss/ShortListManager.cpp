#include "Header.h"
#include "ShortListManager.h"

void ShortListManager::loadData()
{
	std::ifstream fin;
	fin.open("ShortListData.txt");
	std::string key;
	std::string val;

	while (!fin.eof()) 	{
		std::getline(fin, key);
		if (key != "") {
			std::getline(fin, val);
			shortList.insert({ key, val });
		}
	}
	std::cout << "\n Data has been loaded";
	fin.close();

}

void ShortListManager::saveData()
{
	std::ofstream fout;
	fout.open("ShortListData.txt");
	for (const auto& elem : shortList) {
		fout << elem.first << std::endl;
		fout << elem.second << std::endl;
	}
	std::cout << "\n Changes has been saved";
	fout.close();
}

void ShortListManager::saveAllData()
{
	vocab.insert(shortList.begin(), shortList.end());

	std::ofstream fout;
	fout.open("Data.txt");
	for (const auto& elem : vocab) {
		fout << elem.first << std::endl;
		fout << elem.second << std::endl;
	}
	fout.close();
}

void ShortListManager::displayData()
{
	system("cls");
	if (shortList.empty()) {
		std::cout << "\n There are nothing to display.";
	}
	else {
		std::cout << "\n There are " << shortList.size() << " words in ShortList" << std::endl;
		std::cout << "========================================" << std::endl;
		for (const auto& elem : shortList) {
			std::cout << " - " << elem.first;
			std::cout << " => " << elem.second;
			std::cout << std::endl;
		}
	}
}

void ShortListManager::addData()
{
	int N = 0;
	std::string key;
	std::string val;
	std::cout << "\n Please input quantity of words for ShortList - ";
	std::cin >> N;
	std::cin.ignore();
	for (int i = 0; i < N; i++) {
		system("cls");
		std::cout << "\n Input " << i + 1 << " word " << std::endl;
		std::getline(std::cin, key);
		std::cout << " - translation " << val << std::endl;
		std::getline(std::cin, val);
		shortList.insert({ key, val });
	}
	saveData();
	saveAllData();
}

void ShortListManager::deleteData()
{
	shortList.clear();
	saveData();
}


