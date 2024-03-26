#pragma once
#include <ncurses.h>
#include <string>
#include <vector>
class ScreenDrawer
{
public:
    void drawFrame(int y, int x, const std::string& content);
    void drawCorridor(const std::vector<int>& corridor);
};

