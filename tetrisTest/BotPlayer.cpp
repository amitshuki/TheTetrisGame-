#include "BotPlayer.h"

void BotPlayer::playerFlow()
{
	bool flag = true;
	int maxCounter = 0; int  blockIndex;
	size_t routateCounter=0;

	int* arr = hightisArray();

	while (flag) {
		blockIndex = findSpacesSequence(arr, &maxCounter);
		if (maxCounter == 0) break;
		if (maxCounter > BLOCKSIZE) {
			routateCounter = findMaxBase();

			flag = false;
		}
		else {
			for (int i = maxCounter; i > 0; i--) {
				routateCounter = findShapeByRotate(i);
				if (routateCounter != BLOCKSIZE) {
					flag = false;
					break;
				}
			}
			updateArray(arr, blockIndex, maxCounter);//delete the max for go the next one in this hight
		}
		
	}
	botPath(routateCounter, blockIndex, arr[blockIndex]);
	delete arr;

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
			if (board.block.getBlockChar(i, j) == '&')
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
			if (board.block.getBlockChar(j, i) == '&')
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
			if (board.block.getBlockChar(j, i) == '&')
				baseCounterLeft++;
		}
		if (baseCounterLeft != 0)
			break;
	}
	return baseCounterLeft;
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


int* BotPlayer::hightisArray() {
	int* arr = new int[COLS];

	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++)
			if (board.getBlockChar(i, j) == '#' || j == ROWS - 1) {
				arr[i] = j;
				break;
			}


	}
	return arr;

}

int BotPlayer::findSpacesSequence(int* arr, int* maxCounter) {
	int min = arr[0];
	bool firstrun = true;
	for (size_t i = 0; i < COLS; i++) {
		if (min < arr[i])
			min = arr[i];
		if (i < COLS - 1) {
			if (arr[i] != arr[i + 1])
				firstrun = false;
		}
	}

	int counter = 0;

	int savedIndex = 0;
	for (size_t i = 0; i < COLS; i++) {
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
	if (firstrun) {
		*maxCounter = counter;
	}
	return savedIndex;

}

void BotPlayer::updateArray(int* arr, int blockIndex, int maxCounter) {
	for (int i = blockIndex; i < blockIndex + maxCounter; i++)
		arr[i] = 0;

}

void BotPlayer::botPath(int routateCounter, int _x, int _y) {
	int index = 0;
	int left = board.block.getX() - _x;
	int down = board.block.getY() - _y;
	MovePath = new int[abs(down)+abs(left)];
	while (left != 0 && down != 0) {
		if (left < 0) {
			MovePath[index] = LEFT;
			left++;
			index++;
			down++;
		}
		if (left > 0) {
			MovePath[index] = RIGHT;
			left--;
			index++;
			down++;
		}
		if (routateCounter == 1 || routateCounter == 3) {
			MovePath[index] = ROTATER;
			index++;
			down++;

			if (routateCounter == 3) {
				MovePath[index] = ROTATER;
				index++;
				down++;
			}
			routateCounter = 0;
		}
		if (routateCounter == 2) {
			MovePath[index] = ROTATEL;
			index++;
			down++;
			routateCounter = 0;
		}
		if (left == 0 && routateCounter == 0) {
			while (down != 0) {
				MovePath[index] = DOWN;
				index++;
				down++;
			}
		}

		MovePath[index] = -1;//flag for end of array 

	}
		

}

void BotPlayer::clearSteps() {
	for (size_t i = 0; i < COLS + ROWS-1; i++)
		MovePath[i] =DOWN;

		MovePath[COLS + ROWS - 1] =-1;
		

}