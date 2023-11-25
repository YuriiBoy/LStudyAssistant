#pragma once

class VocabManager
{
	std::map<std::string, std::string> dict;
public:
	void loadData();
	void saveData();
	void displayData();
	void changeData();
	void searchData();
	void deleteData();
};

