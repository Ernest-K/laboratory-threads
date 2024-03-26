#pragma once
#include <ncurses.h>
#include <string>
#include <vector>
class ScreenDrawer
{
public:
    void drawFrame(int y, int x, const std::string& content1, const std::string& content2);
    void drawCorridor(const std::vector<int>& corridor1, const std::vector<int>& corridor2);
};

