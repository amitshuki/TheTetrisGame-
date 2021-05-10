#include "BotPlayer.h"

void BotPlayer::playerFlow()
{
	int spaces, shapeSide;
	bool ifPossibleToDrop;

	for (size_t i = ROWS; i < 0; i--)
	{
			spaces = spaceCounter(i);

			if (spaces > 4)
				shapeSide=findMaxBase();
			else
				for (size_t j = spaces; j > 0; j--)
					shapeSide=findShapeByRotate(j);

			
			//ifPossibleToDrop = board.isCollide(i, j);
	}
}

int BotPlayer::findMaxBase()
{
	int baseCounterUp = findBaseUp();
	int baseCounterDown = findBaseDown();
	int baseCounterRight = findBaseRight();
	int baseCounterLeft = findBaseLeft();
	int MaxBase = baseCounterUp;
	int rotate = 0;

	if (baseCounterDown > MaxBase)
	{
		MaxBase = baseCounterDown;
		rotate = 1;
	}
	if (baseCounterRight > MaxBase)
	{
		MaxBase = baseCounterRight;
		rotate = 2;
	}
	if (baseCounterLeft > MaxBase)
	{
		MaxBase = baseCounterLeft;
		rotate = 3;
	}
	return rotate;
}

int BotPlayer::findBaseUp()
{
	int baseCounterUp = 0;
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (board.block.getBlockChar(j, i) == '&')
				baseCounterUp++;
		}
		if (baseCounterUp != 0)
			break;
	}
	return baseCounterUp;
}

int BotPlayer::findBaseDown()
{
	int baseCounterDown = 0;
	for (size_t i = BLOCKSIZE - 1; i <= 0; i--)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (board.block.getBlockChar(j, i) == '&')
				baseCounterDown++;
		}
		if (baseCounterDown != 0)
			break;
	}
	return baseCounterDown;
}

int BotPlayer::findBaseRight()
{
	int baseCounterRight = 0;
	for (size_t i = BLOCKSIZE - 1; i <= 0; i--)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (board.block.getBlockChar(i, j) == '&')
				baseCounterRight++;
		}
		if (baseCounterRight != 0)
			break;
	}
	return baseCounterRight;
}

int BotPlayer::findBaseLeft()
{
	int baseCounterLeft = 0;
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (board.block.getBlockChar(i, j) == '&')
				baseCounterLeft++;
		}
		if (baseCounterLeft != 0)
			break;
	}
	return baseCounterLeft;
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
	int base = BLOCKSIZE;
	if (spaces == findBaseUp())
		return 0;
	if (spaces == findBaseDown())
		return 1;
	if (spaces == findBaseRight())
		return 2;
	if (spaces == findBaseLeft())
		return 3;

	return base;
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

int* BotPlayer::hightisArray() {
	int* arr = new int[COLS];

	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++)
			if (board.getBlockChar(i,j) == '#' || j == ROWS - 1) {
				arr[i] = j;
				break;
			}
				
	
	}
	return arr;

}

int BotPlayer::findSpacesSequence(int* arr, int * maxCounter) {
	int min = arr[0];
	
	for (size_t i = 0; i < COLS; i++) {
		if(min < arr[i])
			min = arr[i]  ;
	}

	int counter = 0;
	
	int savedIndex = 0;
	for (size_t i = 0; i < COLS ; i++) {
		if (arr[i] != min) {
			if (*maxCounter < counter) {
			*maxCounter = counter;
			savedIndex = i - *maxCounter;
			counter = 0;
			}
		
		}
		else 
			counter++;
	}	
	
	return savedIndex;

}