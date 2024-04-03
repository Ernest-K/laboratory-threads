// laboratory-threads.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <ncurses.h>
#include <iostream>
#include <thread>
#include <mutex>
#include "Organism.h"
#include <vector>
#include "Distributor.h"
#include "ScreenDrawer.h"
#include "Assistant.h"

void drawFrame(int y, int x, const std::string& content) {
    mvprintw(y, x, "| %s |", content.c_str());
}

int main()
{
    std::mutex mtx_distributor, mtx_corridor, mtx_bowl;

    Distributor distributor;

    int numberOfAssistants = 3;
    std::vector<Assistant> assistants;
    std::vector<std::thread> assistantThreads;

    std::vector<Organism> organisms;
    std::vector<std::thread> organismThreads;

    int numberOfPositions = 10;
    std::vector<int> corridor(numberOfPositions, -1);
    std::vector<int> bowl(numberOfPositions, 10);


    for (int i = 0; i < numberOfAssistants; ++i) {
        assistants.push_back(Assistant(i + 1, i, 50));
    }

    for (int i = 0; i < numberOfAssistants; ++i) {
        assistantThreads.push_back(std::thread(&Assistant::work, &assistants[i], std::ref(mtx_distributor), std::ref(distributor), std::ref(mtx_corridor), std::ref(corridor), std::ref(mtx_bowl), std::ref(bowl), std::ref(organisms)));
    }

    for (int i = 0; i < numberOfAssistants; ++i) {
        corridor[i] = i + 1;
    }

    for (int i = 0; i < numberOfPositions; ++i) {
        organisms.push_back(Organism(i, 5));
    }

    initscr();
    mvprintw(0, 2, "Distibutor:");
    mvprintw(6, 5, "|   |");
    ScreenDrawer sc;
    sc.drawCorridor(corridor);
    sc.drawBowls(bowl);
    sc.drawOrganisms(organisms);

    for (int i = 0; i < numberOfPositions; ++i) {
        organismThreads.push_back(std::thread(&Organism::work, &organisms[i], std::ref(mtx_bowl), std::ref(bowl[i])));
    }

    for (int i = 0; i < numberOfPositions; ++i) {
        organismThreads[i].join();
    }

    for (int i = 0; i < numberOfAssistants; ++i) {
        assistantThreads[i].join();
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
