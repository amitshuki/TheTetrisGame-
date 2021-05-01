#pragma once
#include"Shape.h"
#include <Cstdlib>

enum { MID = 5, UP = 0, BLOCKSIZE = 4 };

class Board;
class Block
{

	char block[BLOCKSIZE][BLOCKSIZE];
	int x = MID;
	int y = UP;
	Shape s;
public:
	Board* board;

public:
	bool rotateBolck(int n);
	
	const char getBlockChar (int  i, int j)  const { return block[i][j]; }
	void spwanBlock();
	void updateblock();
	const  int getX() const { return x; }
	const  int getY()const { return y; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void SetBlockChar(int i, int j, char c) { block[i][j] = c; }
};

