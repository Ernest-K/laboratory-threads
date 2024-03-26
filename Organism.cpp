#include "Organism.h"
#include <thread>
#include <chrono>

Organism::Organism()
{
}

Organism::Organism(int id, int stamina)
{
	this->id = id;
	this->stamina = stamina;
}

void Organism::work(std::mutex& mtxBowl, int& bowl)
{
	std::srand(std::time(nullptr));
	while (stamina > 0) {
		int randomMilliseconds = std::rand() % 401 + 800;
		std::this_thread::sleep_for(std::chrono::milliseconds(randomMilliseconds));
		if (bowl == 0) {
			stamina--;
			mvprintw(0, 45, "Stamina:");
			mvprintw(2 + id, 45, " | %d | ", stamina);
		}
		if (bowl > 0) {
			mtxBowl.lock();
			bowl--;
			mvprintw(0, 30, "Bowls:");
			mvprintw(2 + id, 30, " | %d | ", bowl);
			mtxBowl.unlock();
		}
	}
}
