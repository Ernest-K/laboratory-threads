#include "Assistant.h"
#include "Distributor.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

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

void Assistant::work(std::mutex& mtxDistributor, Distributor& distributor, std::mutex& mtxCorridor, std::vector<int>& corridor)
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

		cout << "Assistant number: " << id << endl;

		for (int element : corridor) {
			std::cout << element << " ";
		}
		std::cout << std::endl;


		this->feed();

		int randomMilliseconds = std::rand() % 401 + 800;

		std::this_thread::sleep_for(std::chrono::milliseconds(randomMilliseconds));
	}
}


bool Assistant::needRefill()
{
	if (food < minFoodLevel) {
		std::cout << this->id << "\tneed refill" << endl;
		return true;
	}
	return false;
}

// TO DO ZMIANY
void Assistant::feed()
{
	if (this->food - 4 >= 0) {
		this->food -= 4;
		std::cout << this->id << "\tfeed" << this->food << endl;
	}
	this_thread::sleep_for(100ms);
}

void Assistant::refill()
{
	std::cout<< this->id << "\trefill" << endl;
	this_thread::sleep_for(10ms * (this->foodCapacity - this->food));
	this->food = 50;
}

void Assistant::moveUp(std::vector<int>& corridor) {
	corridor[(position)] = -1;
	corridor[(position - 1)] = id;
	this->position = (this->position - 1);
}

void Assistant::moveDown(std::vector<int>& corridor) {
	corridor[(position)] = -1;
	corridor[(position + 1)] = id;
	this->position = (this->position + 1);
}

bool Assistant::canMoveUp(std::vector<int>& corridor) {
	if (position - 1 >= 0 && corridor[(position - 1)] == -1) {
		return true;
	}

	this->direction = 1;
	return false;
}

bool Assistant::canMoveDown(std::vector<int>& corridor) {
	if (position + 1 < corridor.size() && corridor[(position + 1)] == -1) {
		return true;
	}

	this->direction = -1;
	return false;
}
