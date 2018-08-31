#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Sea.h"

int main() {
	srand((unsigned int)time(NULL));
	Sea sea;
	sea.init();//��ʼ����
	Ship ship[5] = { 2,2,3,4,5 };
	//�ڴ�����Ӵ�ֻ
	for (int i = 0; i < 5; i++) {
		sea.addShip(ship[i]);
	}
	while (true) {
		sea.reload();
		//sea.showSea();//�����ú������򿪿��Կ�����ֻ�ֲ�
		printf("����������(���� A3)��\n");
		int x = fgetc(stdin) - 'A';
		int y = fgetc(stdin) - '1';
		while (fgetc(stdin) != '\n');
		if (x < 0 || x > 7 || y < 0 || y>7) {
			printf("�����ʽ����\n");
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