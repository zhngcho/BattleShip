#pragma once
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Ship.h"
#include "Bomb.h"
class Sea
{
public:
	Sea();
	~Sea();
	void init();//初始化大海
	void reload();//重新加载大海画面
	bool addShip(Ship ship);//在大海上为船只添加位置
	void beStruck(Bomb b);//炸弹炸在海中
	bool isSuccessed();

	void showSea();

private:
	Grid area[SEAWIDTH][SEALENGTH];
	std::vector<Ship> ships;
};

