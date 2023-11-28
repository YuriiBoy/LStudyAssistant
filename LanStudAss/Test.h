#pragma once

class Test
{
	int id;
	std::string key;
	std::string val;
	int quest;
	int ransw;
	int percent;

public:
	Test();
	Test(int id, std::string key, std::string val, int quest, int ransw, int percent);
	int getId() const;
	std::string getKey() const;
	std::string getVal() const;
	int getQuest();
	int getRansw();
	int getPercent();
	void display() const;
};

