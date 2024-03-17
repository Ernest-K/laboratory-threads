#include "Organism.h"

Organism::Organism()
{
}

Organism::Organism(int id, int stamina)
{
	this->id = id;
	this->stamina = stamina;
}

void Organism::work(std::mutex& mtxBowl, std::vector<int>& bowl)
{
}
