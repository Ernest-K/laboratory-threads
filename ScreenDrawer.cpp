#include "ScreenDrawer.h"
#include "Assistant.h"
#include "Organism.h"

void ScreenDrawer::drawFrame(int y, int x, const std::string& content) {
    mvprintw(y, x, " | %s | ", content.c_str());
}

void ScreenDrawer::drawCorridor(const std::vector<int>& corridor) {
    mvprintw(0, 15, "Workers:");
    for (int i = 0; i < corridor.size(); ++i) {
        if (corridor[i] != -1) {
            drawFrame(2 + i, 15, std::to_string(corridor[i]), "50");
        }
        else {
            drawFrame(2 + i, 15, "    ");
        }
    }
    refresh();
}

void ScreenDrawer::drawBowls(const std::vector<int>& bowl) {
    mvprintw(0, 30, "Bowls:");
    for (int i = 0; i < bowl.size(); ++i) {
        if (bowl[i] != -1) {
            drawFrame(2 + i, 30, std::to_string(bowl[i]));
        }
        else {
            drawFrame(2 + i, 30, " ");
        }
    }
    refresh();
}

void ScreenDrawer::drawOrganisms(const std::vector<Organism>& organisms) {
    mvprintw(0, 45, "Stamina:");
    for (int i = 0; i < organisms.size(); ++i) {
        if (organisms[i].stamina != -1) {
            drawFrame(2 + i, 45, std::to_string(organisms[i].stamina));
        }
        else {
            drawFrame(2 + i, 45, " ");
        }
    }
    refresh();
}

void ScreenDrawer::drawFrame(int y, int x, const std::string& content, const std::string& content2) {
    mvprintw(y, x, " | %s_%s | ", content.c_str(), content2.c_str());
}

void ScreenDrawer::drawCorridor(const std::vector<int>& corridor, Assistant* a) {
    mvprintw(0, 15, "Workers:");
    for (int i = 0; i < corridor.size(); ++i) {
        if (corridor[i] != -1) {
            if (a->position == i) {
                drawFrame(2 + i, 15, std::to_string(corridor[i]), std::to_string(a->food));
            }
        }
        else {
            drawFrame(2 + i, 15, "    ");
        }
    }
    refresh();
}