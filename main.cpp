#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Sea.h"

int main() {
	srand((unsigned int)time(NULL));
	Sea sea;
	sea.init();//初始化大海
	Ship ship[5] = { 2,2,3,4,5 };
	//在大海中添加船只
	for (int i = 0; i < 5; i++) {
		sea.addShip(ship[i]);
	}
	while (true) {
		sea.reload();
		//sea.showSea();//调试用函数，打开可以看到船只分布
		printf("请输入坐标(例如 A3)：\n");
		int x = fgetc(stdin) - 'A';
		int y = fgetc(stdin) - '1';
		while (fgetc(stdin) != '\n');
		if (x < 0 || x > 7 || y < 0 || y>7) {
			printf("输入格式错误\n");
			continue;
		}
		sea.beStruck(Bomb(x, y));
		if (sea.isSuccessed()) {
			break;
		}
	}
	system("cls");
	printf("Congratulations!\nBombs used: %d\n", Bomb::getSumBomb());
	system("pause");
	return 0;
}