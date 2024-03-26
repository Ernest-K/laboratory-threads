#pragma once
#include <ncurses.h>
class Distributor
{
	public:
		int occupiedBy = -1;
		bool isFree();
		void occupy(int assistantId);
		void release();
};

