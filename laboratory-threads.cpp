﻿// laboratory-threads.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <mutex>
#include "Assistant.h"
#include <vector>
#include "Distributor.h"

int main()
{
    int numberOfAssistants = 3;
    std::vector<Assistant> assistants(numberOfAssistants);

    std::mutex mtx_distributor;
    Distributor distributor;

    Assistant a1(1, 1, 40);
    Assistant a2(2, 2, 40);
    Assistant a3(3, 3, 40);

    std::thread t1(&Assistant::work, &a1, std::ref(mtx_distributor), std::ref(distributor));
    std::thread t2(&Assistant::work, &a2, std::ref(mtx_distributor), std::ref(distributor));
    std::thread t3(&Assistant::work, &a3, std::ref(mtx_distributor), std::ref(distributor));

    t1.join();
    t2.join();
    t3.join();
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
