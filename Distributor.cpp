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
	this->occupiedBy = assistantId;
}

void Distributor::release()
{
	this->occupiedBy = -1;
}
