#pragma once
class Point
{
	size_t x =0;
	size_t y =0;
	
public:
	Point(size_t _x, size_t _y) {
		x = _x;
		y = _y;
	}
	Point() {}
		inline size_t getX() { return x; }
	inline size_t getY() { return y; }
	inline void setX(size_t x) { this->x=x; }
	inline void setY(size_t y) { this->y = y; }
};

