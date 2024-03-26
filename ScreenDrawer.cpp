#include "ScreenDrawer.h"

void ScreenDrawer::drawFrame(int y, int x, const std::string& content1, const std::string& content2) {
    mvprintw(y, x, " | %s_%s | ", content1.c_str(), content2.c_str());
}

void ScreenDrawer::drawCorridor(const std::vector<int>& corridor1, const std::vector<int>& corridor2) {
    mvprintw(0, 16, "Workers:\n");
    for (size_t i = 0; i < corridor1.size(); ++i) {
        if (corridor1[i] != -1 && corridor2[i] != -1) {
            drawFrame(2 + i, 15, std::to_string(corridor1[i]), std::to_string(corridor2[i]));
        }
        else {
            drawFrame(2 + i, 15, " ", " ");
        }
    }
    refresh();
}