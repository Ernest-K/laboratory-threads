#include "Organism.h"

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
		}
		if (bowl > 0) {
			mtxBowl.lock();
			bowl--;
			mtxBowl.unlock();
		}
		std::cout << "Bowl number " << id << " " << bowl << " stamina: " << stamina << std::endl;
	}
}
