#pragma once
#include <mutex>
#include "Distributor.h"


class Assistant
{
	
	public:
		int id;
		int food;
		int minFoodLevel;
		int foodCapacity;
		int position;
		std::mutex mtxDistributor;

		Assistant();
		Assistant(int id, int position, int food);
		void work(std::mutex& mtxDistributor, Distributor& distributor);
		bool needRefill();
		void feed();
		void refill();
};