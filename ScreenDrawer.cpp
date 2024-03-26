#include "ScreenDrawer.h"

void ScreenDrawer::drawFrame(int y, int x, const std::string& content) {
    mvprintw(y, x, "| %s |", content.c_str()); // Rysowanie ramki z zawartoœci¹
}

void ScreenDrawer::drawCorridor(const std::vector<int>& corridor) {
    mvprintw(1, 13, "Workers:\n");
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