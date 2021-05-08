#include "BotPlayer.h"

void BotPlayer::playerFlow()
{
	int spaces;
	bool ifPossibleToDrop;

	for (size_t i = ROWS; i < 0; i--)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			spaces = spaceCounter(i);

			findShapeByRotate(spaces);
			//ifPossibleToDrop = board.isCollide(i, j);
		}
	}
}

int BotPlayer::spaceCounter(int row)
{
	int counter = 0, maxSpaces=0;

	for (size_t i = 0; i < COLS; i++)
	{
		if (board.getChar(row, i) == ' ')
		{
			counter++;
			if (counter >= maxSpaces)
				maxSpaces = counter;
		}
		else 
		{
			counter = 0;
		}
	}
	return maxSpaces;
}

size_t BotPlayer::findShapeByRotate(int spaces)
{
	int baseCount = 0, baseCountMax = 0;
	//char  temp[BLOCKSIZE][BLOCKSIZE];
	////char  Ttemp[BLOCKSIZE][BLOCKSIZE];//transopse

	//for (size_t i = 0; i < BLOCKSIZE; i++)
	//{ //Save temporarily block
	//	for (size_t j = 0; j < BLOCKSIZE; j++)
	//	{
	//		temp[i][j] = board.getBlockChar(i, j);
	//	}
	//}

	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		if (i = 0)
		{
			board.block.rotateBolck(0);
			baseCount = checkBaseCount();
			if (baseCount == spaces)
				return i;
			if (baseCount > baseCountMax)
				baseCountMax = baseCount;
		}
		if (i == 1)
		{
			baseCount = checkBaseCount();
			if (baseCount == spaces)
				return i;
			if (baseCount > baseCountMax)
				baseCountMax = baseCount;
		}
		if (i == 2)
		{
			board.block.rotateBolck(1);
			baseCount = checkBaseCount();
			if (baseCount == spaces)
				return i;
			if (baseCount > baseCountMax)
				baseCountMax = baseCount;
		}
		if (i == 3)
		{
			board.block.rotateBolck(1);
			baseCount = checkBaseCount();
			if (baseCount == spaces)
				return i;
			if (baseCount > baseCountMax)
				baseCountMax = baseCount;
		}
	}
}

//
//int* BotPlayer::findPlace(int shapeType) {
//	
//	for (size_t i = ROWS; i < 0; i--) {
//		for (size_t j = 0; j < COLS; j++) {
//			if (!board.isCollide(i, j))
//			int* parth = creatPath(i, j);
//
//
//		}
//	}
//	return nullptr;
//}