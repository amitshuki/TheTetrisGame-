#pragma once
#include "Point.h"
#include "gotoxy.h"
#include<conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "Block.h"

const size_t ROWS = 18;
const size_t COLS = 12;


class Board
{
	char boardGame[COLS][ROWS];

	char floor = 94;
	char wall = '|';
	Point point;
	//block start cord
	Block block;
	bool isgameOver = false;
	char Keys[5];




	void refreshLines(int row);
	void deleteLine(int row);

	void collide();
	bool isInBoard(int x, int y);




public:
	bool isCollide(int x, int y);
	bool getIsGameOVER() { return isgameOver; };
	void BoardInit(Point _p, char* _keys);
	void printboard(Point p);
	void display();
	void userInput(char key = 0);
	void setGameOver(bool a) { isgameOver = a; }
	Point& getPoint() { return point; }
	void setPoint(Point _p) {
		point.setX(_p.getX());
		point.setY(_p.getY());
	}
	char getKey(size_t i) const { 
		if (0 <= i && i < 5)
			return Keys[i];
		return '0';
	}
	void setKeys(char* key);
	void clearBlock();
	void FixBoard();
	void addShape();
	void removeBlock(int _x, int _y);
	void checkLine();
};
