#pragma once
#include "Player.h"
#include "constans.h"
#include <cstdlib>
class BotPlayer :Player
{
	
	int* MovePath;

	bool findPlace(int shapeType);
	void playerFlow();
	int spaceCounter(int row);
	size_t findShapeByRotate(int spaces);
	int* hightisArray();
	int findSpacesSequence(int* arr, int* maxCounter);
	int findMaxBase();
	int findBaseUp();
	int findBaseDown();
	int findBaseRight();
	int findBaseLeft();
	void updateArray(int* arr, int blockIndex, int maxCounter);
	void botPath(int routateCounter, int _x, int _y);
	

};

