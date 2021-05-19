#include "BotPlayer.h"

void BotPlayer::playerFlow(int type)
{
	bool flag = true;
	int maxCounter = 0; int  blockIndex;
	size_t routateCounter = 0;

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
			if (routateCounter == BLOCKSIZE || !isWideEnough(blockIndex)) {
				updateArray(arr, blockIndex, maxCounter);//delete the max for go the next one in this hight
				flag = true;
			}
		}

	}
	botPath(routateCounter, blockIndex, arr[blockIndex]);
	if (type == 1) {
		int i = 0;
		while (MovePath[i] != -1) {
			if (i % 10 == 0) {
				MovePath[i] = rand() % 6;
			}
			i++;
		}
		
	}
	if (type == 2) {
		int i = 0;
		while (MovePath[i] != -1) {
			if (i % 40 == 0) {
				MovePath[i] = rand() % 6;
			}
			i++;
		}
	}
	delete arr;

}

int BotPlayer::findMaxBase()
{
	int baseCounterUp = findBaseUp();
	int baseCounterDown = findBaseDown();
	int baseCounterRight = findBaseRight();
	int baseCounterLeft = findBaseLeft();
	int MaxBase = baseCounterDown;
	int rotate = 0;


	if (baseCounterRight > MaxBase)
	{
		MaxBase = baseCounterRight;
		rotate = 1;
	}
	if (baseCounterLeft > MaxBase)
	{
		MaxBase = baseCounterLeft;
		rotate = 2;
	}
	if (baseCounterUp > MaxBase)
	{
		MaxBase = baseCounterUp;
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
	for (int i = BLOCKSIZE - 1; i >= 0; i--)
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
	for (size_t i = BLOCKSIZE - 1; i >= 0; i--)
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




size_t BotPlayer::findShapeByRotate(int spaces)
{
	int base = BLOCKSIZE;
	if (spaces == findBaseDown())
		return 0;
	if (spaces == findBaseLeft())
		return 1;
	if (spaces == findBaseRight())
		return 2;
	if (spaces == findBaseUp())
		return 3;

	return base;
}


int* BotPlayer::hightisArray() {
	int* arr = new int[COLS];

	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++) {
			if (board.getChar(i, j) == '#') {
				arr[i] = j - 1;
				break;
			}
			else if (j == ROWS - 1)
				arr[i] = j;


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
	if (firstrun || counter > * maxCounter) {
		savedIndex = (COLS - 1) - *maxCounter;
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
	int shapeX, shapeY;
	findcord(&shapeX, &shapeY);
	int left = board.block.getX() + shapeX - _x;
	int down = board.block.getY() + shapeY - _y;
	delete MovePath;
	MovePath = new int[abs(down) + abs(left) + routateCounter];
	while (left != 0 && down != 0) {
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
		if (left > 0) {
			MovePath[index] = LEFT;
			left--;
			index++;
			down++;
		}
		if (left < 0) {
			MovePath[index] = RIGHT;
			left++;
			index++;
			down++;
		}


		if (left == 0 && routateCounter == 0) {
			while (down != 0) {
				MovePath[index] = DOWN;
				index++;
				down++;
			}
		}



	}
	MovePath[index] = -1;//flag for end of array 

}
void BotPlayer::findcord(int* shapeX, int* shapeY) {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			if (board.getBlockChar(i, j) == '&') {
				*shapeX = i;
				*shapeY = j;
				return;
			}
		}
	}

}
bool BotPlayer::isWideEnough(int index) {
	
	int counter = 0;
	int maxCounter = 0;
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		counter = 0;
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (board.getBlockChar(j, i) == '&')
				counter++;

		
		}
		if(counter>maxCounter)maxCounter=counter;
	}
	return (gapbetween(maxCounter, index));
	
}
bool BotPlayer::gapbetween(int maxCounter, int index) {
	int indexHigh = -1;
	int leftHigh = -1;
	int rightHigh = -1;
	for (int i = 0; i < ROWS; i++) {
		if (board.getChar(index, i) == '#') {
			indexHigh = i;
			break;
			
		}
		if (i == ROWS - 1)indexHigh = i;
	}
	if (index != 0) {
		for (int i = 0; i < ROWS; i++) {
			if (board.getChar(index - 1, i) == '#') {
				leftHigh = i;
				break;
			}
			if (i == ROWS - 1)leftHigh = i;
		}
	}
	if (index != COLS-1) {
		for (int i = 0; i < ROWS; i++) {
			if (board.getChar(index + 1, i) == '#') {
				rightHigh = i;
				break;
			}
			if (i == ROWS - 1)rightHigh = i;
		}
	}

	if (index==0) {
		if (indexHigh-rightHigh <= maxCounter) {
			return true;
		}
		else return false;
	}
	if (index == COLS - 1) {
		if (indexHigh-leftHigh <= maxCounter) {
			return true;
		}
		else return false;
	}
	if (indexHigh- leftHigh <= maxCounter && indexHigh-rightHigh  <= maxCounter)
		return true;
		else return false;
}