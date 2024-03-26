#include "ScreenDrawer.h"
#include "Organism.h"

void ScreenDrawer::drawFrame(int y, int x, const std::string& content) {
    mvprintw(y, x, " | %s | ", content.c_str()); // Rysowanie ramki z zawartoœci¹
}

void ScreenDrawer::drawCorridor(const std::vector<int>& corridor) {
    mvprintw(0, 15, "Workers:");
    for (int i = 0; i < corridor.size(); ++i) {
        if (corridor[i] != -1) {
            drawFrame(2 + i, 15, std::to_string(corridor[i])); // Rysowanie ramki z zawartoœci¹
        }
        else {
            drawFrame(2 + i, 15, " "); // Rysowanie pustej ramki
        }
    }
    refresh(); // Odœwie¿enie ekranu
}

void ScreenDrawer::drawBowls(const std::vector<int>& bowl) {
    mvprintw(0, 30, "Bowls:");
    for (int i = 0; i < bowl.size(); ++i) {
        if (bowl[i] != -1) {
            drawFrame(2 + i, 30, std::to_string(bowl[i])); // Rysowanie ramki z zawartoœci¹
        }
        else {
            drawFrame(2 + i, 30, " "); // Rysowanie pustej ramki
        }
    }
    refresh(); // Odœwie¿enie ekranu
}

void ScreenDrawer::drawOrganisms(const std::vector<Organism>& organisms) {
    mvprintw(0, 45, "Stamina:");
    for (int i = 0; i < organisms.size(); ++i) {
        if (organisms[i].stamina != -1) {
            drawFrame(2 + i, 45, std::to_string(organisms[i].stamina)); // Rysowanie ramki z zawartoœci¹
        }
        else {
            drawFrame(2 + i, 45, " "); // Rysowanie pustej ramki
        }
    }
    refresh(); // Odœwie¿enie ekranu
}