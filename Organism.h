#pragma once

#include <mutex>
#include <vector>

class Organism
{
	public:
		int id; //id = place
		int stamina;

		Organism();
		Organism(int id, int stamina);
		void work(std::mutex& mtxBowl, std::vector<int>& bowl);
};

