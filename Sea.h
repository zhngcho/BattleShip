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
	void init();//��ʼ����
	void reload();//���¼��ش󺣻���
	bool addShip(Ship ship);//�ڴ���Ϊ��ֻ���λ��
	void beStruck(Bomb b);//ը��ը�ں���
	bool isSuccessed();

	void showSea();

private:
	Grid area[SEAWIDTH][SEALENGTH];
	std::vector<Ship> ships;
};

