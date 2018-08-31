#include "Bomb.h"

int Bomb::sumBomb = 0;
Bomb::Bomb(int x, int y): x(x), y(y)
{
	sumBomb++;
}

Bomb::~Bomb()
{
}
