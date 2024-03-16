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

}

void Assistant::work(std::mutex& mtxDistributor, Distributor& distributor)
{
	while (true) {
		if (needRefill() && distributor.isFree()) {
			mtxDistributor.lock();
			distributor.occupy(this->id);
			refill();
			distributor.release();
			mtxDistributor.unlock();
		}

		this->feed();

		this_thread::sleep_for(100ms);
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
