#pragma once

class Menu
{
	std::string taskName;
	std::vector <std::string> menuList;
public:
	Menu(std::string taskName, std::vector<std::string> menuList);
	void setEncoding();
	void displayTaskName() const;
	void displayListMenu() const;
	int getChoice() const;
	bool allowContinue() const;
};

