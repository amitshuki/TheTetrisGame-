#pragma once
class Point
{
	int x;
	int y;
	bool inUse;
public:
	Point(int _x, int _y) {
		x = _x;
		y = _y;
		inUse = false;
	}
	Point() {}
	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x=x; }
	void setY(int y) { this->y = y; }
	bool isInUse() { return inUse; }
};

