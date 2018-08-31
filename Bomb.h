#pragma once
class Bomb {
public:
	Bomb(int x, int y);
	~Bomb();
	static int getSumBomb() {
		return sumBomb;
	}
public:
	friend class Sea;
private:
	int x;
	int y;
	static int sumBomb;
};