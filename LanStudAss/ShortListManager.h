#pragma once

class ShortListManager
{
	std::map<std::string, std::string> shortList;
	std::map<std::string, std::string> dict;
public:
	void loadData();
	void saveData();
	void saveAllData();
	void displayData();
	void addData();
	void deleteData();

};

