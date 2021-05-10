#pragma once
#include "Player.h"
class BotPlayer :Player
{
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
	

};

