#pragma once
#include <mutex>
#include <vector>
#include "Distributor.h"


class Assistant
{
	
	public:
		int id;
		int food;
		int minFoodLevel;
		int foodCapacity;
		int position;
		int direction;
		std::mutex mtxDistributor, mtxCorridor;

		Assistant();
		Assistant(int id, int position, int food);
		void work(std::mutex& mtxDistributor, Distributor& distributor, std::mutex& mtxCorridor, std::vector<int>& corridor);
		bool needRefill();
		void feed();
		void refill();
		void moveUp(std::vector<int>& corridor);
		void moveDown(std::vector<int>& corridor);
		bool canMoveUp(std::vector<int>& corridor);
		bool canMoveDown(std::vector<int>& corridor);
};