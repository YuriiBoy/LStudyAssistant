#include "Header.h"
#include "Test.h"

Test::Test() : id(0), key("-"), val("-"), quest(0), ransw(0), percent(0)
{}

Test::Test(int id, std::string key, std::string val, int quest, int ransw, int percent)
	: id(id), key(key), val(val), quest(quest), ransw(ransw), percent(percent)
{}

int Test::getId() const
{
	return id;
}

std::string Test::getKey() const
{
	return key;
}

std::string Test::getVal() const
{
	return val;
}


int Test::getQuest()
{
	return quest;
}

int Test::getRansw()
{
	return ransw;
}

int Test::getPercent()
{
	return percent;
}

void Test::display() const
{
	std::cout << std::setw(5) << id;
	std::cout << std::setw(15) << key;
	std::cout << std::setw(15) << val;
	std::cout << std::endl;
}
