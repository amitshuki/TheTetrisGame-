#pragma once
class Point
{
	int x =0;
	int y =0;
	
public:
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	Point() {}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void setX(int x) { this->x=x; }
	inline void setY(int y) { this->y = y; }
};

