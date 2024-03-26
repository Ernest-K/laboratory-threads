#pragma once
#include <ncurses.h>
#include <vector>
#include <string>

class Display
{
public:
	void displayTwoArrays(const std::vector<int>& corridor, const std::vector<int>& bowl);
	void drawFrame(int y, int x, const std::string& content1, const std::string& content2);
};

