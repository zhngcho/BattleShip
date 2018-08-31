#pragma once
#include "util.h"
class Ship
{
public:
	Ship();
	~Ship();
	Ship(int size);
public:
	friend class Sea;
private:
	int size;
	Position pos[SEAWIDTH];
};

