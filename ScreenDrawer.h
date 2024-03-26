#pragma once
#include <ncurses.h>
#include <string>
#include <vector>
#include "Organism.h"

class Assistant;

class ScreenDrawer
{
public:
    void drawFrame(int y, int x, const std::string& content);
    void drawCorridor(const std::vector<int>& corridor);
    void drawBowls(const std::vector<int>& bowl);
    void drawOrganisms(const std::vector<Organism>& organisms);
    

    void drawCorridor(const std::vector<int>& corridor, Assistant* a);
    void drawFrame(int y, int x, const std::string& content, const std::string& content2);
};

