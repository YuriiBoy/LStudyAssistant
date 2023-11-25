#include"Header.h"
#include "VocabManager.h"

void VocabManager::loadData()
{
	
	std::ifstream fin;
	fin.open("Data.txt");
	std::string key;
	std::string val;

	while (!fin.eof()) {
		std::getline(fin, key);
		if (key != "") {
			std::getline(fin, val);
			dict.insert({ key, val });
		}
	}
	std::cout << "\n Data has been loaded";
	fin.close();
}

void VocabManager::saveData()
{
	std::ofstream fout;
	fout.open("Data.txt");
	for (const auto& elem : dict) {
		fout << elem.first << std::endl;
		fout << elem.second << std::endl;
	}
	std::cout << "\n Changes has been saved";
	fout.close();
}

void VocabManager::displayData()
{
	system("cls");
	loadData();
	if (dict.empty()) {
		std::cout << "\n There are nothing to display.";
	}
	else {
		std::cout << "\n There are " << dict.size() << " words in Dictionary" << std::endl;
		std::cout << "========================================" << std::endl;
		for (const auto& elem : dict) {
			std::cout << " - " << elem.first;
			std::cout << " => " << elem.second;
			std::cout << std::endl;
		}
	}
}

void VocabManager::changeData()
{
	system("cls");
	std::string key;
	std::string val;
	char choice;

	std::cout << "\n Please write the word to make changes in Dictionary - ";
	std::cin.ignore();
	std::getline(std::cin, key);
	auto iter = dict.find(key);
	if (iter == dict.end()) {
		std::cout << "\n There is no such word in Dictionary";
	}
	else {
		std::cout << " - " << key << " => " << iter->second;
		std::cout << "\n Do you want to correct key-word (y/n) ? - ";
		std::cin >> choice;
		if (choice == 'y') {
			std::cout << " Please write correct key-word - ";
			std::cin.ignore();
			std::getline(std::cin, key);
			dict.insert({ key, iter->second });
			dict.erase(iter);
		}
		else {
			std::cout << " Please write correct translation - ";
			std::cin.ignore();
			std::getline(std::cin, val);
			key = iter->first;
			dict.erase(iter);
			dict.insert({ key , val });
		}
	}
	
	saveData();
	
}

void VocabManager::searchData()
{
	system("cls");
	std::string key;
	std::cout << "\n Please write the word for translation - ";
	std::cin.ignore();
	std::getline(std::cin, key);
	auto iter = dict.find(key);
	if (iter == dict.end()) {
		std::cout << "\n There is no such word in Dictionary";
	}
	else {
		std::cout << " - " << key << " => " << iter->second;
	}
}

void VocabManager::deleteData()
{
	char choice;
	std::cout << "\n Delete the Dictionary (y/n) ? - ";
	std::cin >> choice;
	if (choice != 'y') {
		return;
	}
	else {
		std::cout << "\n Do you realy want to delete the Dictionary (y/n) ? - ";
		std::cin >> choice;
		if (choice != 'y') {
			return;
		}
		else {
			dict.clear();
			saveData();
		}
	}
}
