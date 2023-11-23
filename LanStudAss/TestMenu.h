#pragma once


class TestMenu
{
	std::vector<std::string> testMenu;
public:
	TestMenu(std::vector<std::string> testMenu);
	void displayTestMenu() const;
	int getChoice() const;
};

