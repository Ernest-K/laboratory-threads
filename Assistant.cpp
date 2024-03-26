#include "Assistant.h"
#include "Distributor.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
#include <ncurses.h>
#include "Organism.h"

using namespace std;

Assistant::Assistant()
{
}

Assistant::Assistant(int id, int position, int food)
{
	this->id = id;
	this->position = position;
	this->food = food;
	this->minFoodLevel = 25;
	this->foodCapacity = 50;
	this->direction = -1;
}

void Assistant::drawFrame(int y, int x, const std::string& content) {
	mvaddch(y, x, '|'); // Lewy bok ramki
	mvprintw(y, x + 1, "%s", content.c_str()); // Zawartość ramki
	mvaddch(y, x + content.length() + 1, '|'); // Prawy bok ramki
}

void Assistant::work(std::mutex& mtxDistributor, Distributor& distributor, std::mutex& mtxCorridor, std::vector<int>& corridor, std::mutex& mtxBowl, std::vector<int>& bowl, std::vector<Organism>& organisms)
{
	std::srand(std::time(nullptr));
	while (true) {
		if (needRefill() && distributor.isFree()) {
			mtxDistributor.lock();
			distributor.occupy(this->id);
			refill();
			distributor.release();
			mtxDistributor.unlock();
		}

		if (canMoveUp(corridor) && direction == -1) {
			mtxCorridor.lock();
			moveUp(corridor);
			mtxCorridor.unlock();
		}
		else if (canMoveDown(corridor) && direction == 1) {
			mtxCorridor.lock();
			moveDown(corridor);
			mtxCorridor.unlock();
		}

		this->feed(mtxBowl, bowl, organisms);
	}
}


bool Assistant::needRefill()
{
	if (food < minFoodLevel) {
		//std::cout << this->id << "\tneed refill" << endl;
		return true;
	}
	return false;
}

// TO DO ZMIANY
void Assistant::feed(std::mutex& mtxBowl, std::vector<int>& bowl, std::vector<Organism>& organisms)
{
	if (bowl[position] > 5 || organisms[position].stamina == 0) {
		return;
	}

	int foodToGive = 10 - bowl[position];

	if (food >= foodToGive) {
		bowl[position] = 10;
		food -= foodToGive;
	}
	else {
		bowl[position] += food;
		food = 0;
	}
}

void Assistant::refill()
{
	//std::cout<< this->id << "\trefill" << endl;
	this_thread::sleep_for(10ms * (this->foodCapacity - this->food));
	this->food = 50;
}

void Assistant::moveUp(std::vector<int>& corridor) {
	corridor[(position)] = -1;
	corridor[(position - 1)] = id;
	this->position = (this->position - 1);

	mvprintw(1, 13, "Workers:\n");
	for (int i = 0; i < corridor.size(); ++i) {
		if (corridor[i] != -1) {
			drawFrame(2 + i, 15, std::to_string(corridor[i])); // Rysowanie ramki z zawartością
		}
		else {
			drawFrame(2 + i, 15, " "); // Rysowanie pustej ramki
		}
	}

	refresh(); // Odświeżenie ekranu
}

void Assistant::moveDown(std::vector<int>& corridor) {
	corridor[(position)] = -1;
	corridor[(position + 1)] = id;
	this->position = (this->position + 1);

	mvprintw(1, 13, "Workers:\n");
	for (int i = 0; i < corridor.size(); ++i) {
		if (corridor[i] != -1) {
			drawFrame(2 + i, 15, std::to_string(corridor[i])); // Rysowanie ramki z zawartością
		}
		else {
			drawFrame(2 + i, 15, " "); // Rysowanie pustej ramki
		}
	}

	refresh(); // Odświeżenie ekranu
}

bool Assistant::canMoveUp(std::vector<int>& corridor) {
	int randomMilliseconds = std::rand() % 401 + 800;
	std::this_thread::sleep_for(std::chrono::milliseconds(randomMilliseconds));
	if (position - 1 >= 0 && corridor[(position - 1)] == -1) {
		return true;
	}

	this->direction = 1;
	return false;
}

bool Assistant::canMoveDown(std::vector<int>& corridor) {
	int randomMilliseconds = std::rand() % 401 + 800;
	std::this_thread::sleep_for(std::chrono::milliseconds(randomMilliseconds));
	if (position + 1 < corridor.size() && corridor[(position + 1)] == -1) {
		return true;
	}

	this->direction = -1;
	return false;
}
