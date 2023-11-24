#pragma once

class ShortListManager
{
	std::map<std::string, std::string> shortList;
	std::map<std::string, std::string> vocab;
public:
	void loadData();
	void saveData();
	void saveAllData();
	void displayData();
	void addData();
	void deleteData();

};

