#pragma once
#include "Point.h"
#include "gotoxy.h"
#include<conio.h>
#include "Shape.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <windows.h>
#include <time.h>
const int ROWS = 18;
const int COLS = 12;

enum { MID = 5,UP= 0 , BLOCKSIZE=4};
class Board
{
	char boardGame[COLS][ROWS];
	char stage[COLS][ROWS];

	char floor = 94;
	char wall = '|';

	Shape s;
	char block[4][4];

	Point point;

	int x = 5;
	int y = 0;
	bool isgameOver = false;
	 char Keys[5];

	bool isCollide(int x,int y);

public:
	inline bool getIsGameOVER(){ return isgameOver; };
	void BoardInit(Point _p, char* _keys);
	void printboard(Point p);
	void  addShape();
	void moveBlock(int _x, int _y);
	bool rotateBolck(int n);
	void display();
	void userInput(char key);
	void spwanBlock();
	void collide();
	bool isInBoard(int x, int y);
	void FixBoard();
	inline void setGameOver(bool a) { isgameOver = a; }
	void checkLine();
	void refreshLines(int row);
	void deleteLine(int row);
	inline Point& getPoint() { return point; }
};

