#pragma once
#include "Test.h"

class TestManager
{
	std::vector<Test> test;
	std::vector<Test> testDict;
public:
	void loadShortListData();
	void loadData();
	void display() const;
	void shortListTest();
	void commonTest();
};

