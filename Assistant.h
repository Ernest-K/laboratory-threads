#pragma once
#include <mutex>
#include <vector>
#include "Distributor.h"
#include "Organism.h"
#include "ScreenDrawer.h"


class Assistant
{
	
	public:
		int id;
		int food;
		int minFoodLevel;
		int foodCapacity;
		int position;
		int direction;
		ScreenDrawer sc;

		Assistant();
		Assistant(int id, int position, int food);
		void work(std::mutex& mtxDistributor, Distributor& distributor, std::mutex& mtxCorridor, std::vector<int>& corridor, std::mutex& mtxBowl, std::vector<int>& bowl, std::vector<Organism>& organisms);
		bool needRefill();
		void drawFrame(int y, int x, const std::string& content);
		void feed(std::mutex& mtxBowl, std::vector<int>& bowl, std::vector<Organism>& organisms);
		void refill();
		void moveUp(std::vector<int>& corridor, std::vector<int>& bowl);
		void moveDown(std::vector<int>& corridor, std::vector<int>& bowl);
		bool canMoveUp(std::vector<int>& corridor);
		bool canMoveDown(std::vector<int>& corridor);
};