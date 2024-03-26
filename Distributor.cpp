#include "Distributor.h"

bool Distributor::isFree()
{
	if (this->occupiedBy == -1) {
		return true;
	}
	return false;
}

void Distributor::occupy(int assistantId)
{
	mvprintw(6, 5, "| %d |", assistantId);
	this->occupiedBy = assistantId;
}

void Distributor::release()
{
	mvprintw(6, 5, "|   |");
	this->occupiedBy = -1;
}
