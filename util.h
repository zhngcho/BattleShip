#pragma once
const int SEAWIDTH = 8;
const int SEALENGTH = 8;
struct Position {
	int x;
	int y;
};
enum SeaContent
{
	WATER,
	SHIP,
	SUNKSHIP
};
struct Grid {
	bool isStruck;
	SeaContent content;
};