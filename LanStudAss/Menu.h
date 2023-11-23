#pragma once

class Menu
{
	std::string taskName;
	std::vector <std::string> menuList;
public:
	Menu(std::string taskName, std::vector<std::string> menuList);
	void displayTaskName() const;
	void displayListMenu() const;
	int getChoice() const;
	bool allowContinue() const;
};

