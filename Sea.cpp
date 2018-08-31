#include "Sea.h"

Sea::Sea()
{
	for (int i = 0; i < SEAWIDTH; i++) {
		for (int j = 0; j < SEALENGTH; j++) {
			area[i][j] = { false, WATER };
		}
	}
}

Sea::~Sea()
{
}

void Sea::init()
{
	reload();
}

void Sea::reload()
{
	system("cls");
	printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 \n");
	int i = 0;
	int j = 0;
	char rhead = 'A';
	for (i = 0; i < 8; i++) {
		printf("-----------------------------------\n");
		printf("%c ", rhead++);
		for (j = 0; j < 8; j++) {
			char midCh = ' ';
			switch (area[i][j].content) {
			case WATER:
				midCh = 'W';
				break;
			case SHIP:
				midCh = 'H';
				break;
			case SUNKSHIP:
				midCh = 'S';
				break;
			default:
				printf("wrong status of sea\n");
			}
			if (!area[i][j].isStruck) {
				midCh = ' ';
			}
			printf("| %c ", midCh);
		}
		printf("\n");
	}
}

bool Sea::addShip(Ship ship)
{
	bool flag = true;//flag������ʶ��Ӵ�ֻ�Ƿ�ɹ�
	while (true) {
		int alignment = rand() % 2;//������ķ��� 0 �������1��������
		int xStart = rand() % (SEAWIDTH - ship.size + 1);//�������ʼ��λ��
		int yStart = rand() % (SEALENGTH - ship.size + 1);//�������ʼ��λ��
		if (alignment == 0) {
			//��鵱ǰλ���Ƿ������Ӵ�ֻ
			for (int i = 0; i < ship.size; i++) {
				if (area[xStart][yStart + i].content != WATER) {
					flag = false;
					break;
				}
			}
			//������ԵĻ����ڵ�ǰλ����Ӵ�ֻ
			if (flag) {
				for (int i = 0; i < ship.size; i++) {
					area[xStart][yStart + i].content = SHIP;
					ship.pos[i].x = xStart ;
					ship.pos[i].y = yStart+i;
				}
				break;
			}
		}
		else
		{
			for (int i = 0; i < ship.size; i++) {
				if (area[xStart + i][yStart].content != WATER) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int i = 0; i < ship.size; i++) {
					area[xStart + i][yStart].content = SHIP;
					ship.pos[i].x = xStart +i ;
					ship.pos[i].y = yStart ;
				}
				break;
			}
		}
	}
	ships.push_back(ship);
	return flag;
}

void Sea::beStruck(Bomb b)
{
	if (area[b.x][b.y].isStruck)
		return;
	area[b.x][b.y].isStruck = true;
	switch (area[b.x][b.y].content) {
	case WATER:
	case SUNKSHIP:
		return;
	case SHIP:
		for (auto ship : ships) {
			//�жϼ�������ֻ��
			for (int i = 0; i < ship.size; i++) {
				if (ship.pos[i].x == b.x && ship.pos[i].y == b.y) {
					bool flag = true;//��ʶ��ֻ�Ƿ��û
					//�жϴ�ֻ�Ƿ��û
					for (int i = 0; i < ship.size; i++) {
						flag = flag && area[ship.pos[i].x][ship.pos[i].y].isStruck;
					}
					//��sea�ϱ�ʶ��û��־
					if (flag) {
						for (int i = 0; i < ship.size; i++) {
							area[ship.pos[i].x][ship.pos[i].y].content = SUNKSHIP;
						}
					}
					return;
				}
			}

		}
	}

}

bool Sea::isSuccessed()
{
	int sum = 0;
	for (int i = 0; i < SEAWIDTH; i++) {
		for (int j = 0; j< SEALENGTH; j++) {
			if (area[i][j].content == SUNKSHIP) {
				sum++;
			}
		}
	}
	return sum == 2 + 2 + 3 + 4 + 5 ? true : false;
}

void Sea::showSea()
{
	for (int i = 0; i < SEAWIDTH; i++) {
		for (int j = 0; j < SEALENGTH; j++) {
			printf("%d-%d\t", area[i][j].content, area[i][j].isStruck);
		}
		printf("\n");
	}
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
