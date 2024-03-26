#include "Display.h"


void Display::displayTwoArrays(const std::vector<int>& corridor, const std::vector<int>& bowl) {
    mvprintw(1, 13, "Workers:\n");
    for (int i = 0; i < corridor.size(); ++i) {
        if (corridor[i] != -1) {
            drawFrame(2 + i, 15, std::to_string(corridor[i]), std::to_string(bowl[i])); // Rysowanie ramki z zawartoœci¹
        }
        else {
            drawFrame(2 + i, 15, " ", "  "); // Rysowanie pustej ramki
        }
    }
}


void Display::drawFrame(int y, int x, const std::string& content1, const std::string& content2) {
    mvprintw(y, x, "| %s_%s |", content1.c_str(), content2.c_str()); // Rysowanie ramki z dwoma elementami
}