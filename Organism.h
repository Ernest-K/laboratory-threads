#pragma once

#include <mutex>
#include <vector>
#include <iostream>

class Organism
{
	public:
		int id; //id = place
		int stamina;

		Organism();
		Organism(int id, int stamina);
		void work(std::mutex& mtxBowl, int& bowl);
};

