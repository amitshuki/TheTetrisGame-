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
	char temp[BLOCKSIZE][BLOCKSIZE] = board;

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