#include "Block.h"
#include "Board.h"

void Block::updateblock() {

	int blockType = rand() % 7;
	setX(MID);
	setY(UP);
	int t = rand() % 20;//5%
	if (t == Shape::BOMB) {
		s.setShape(Shape::BOMB);
		type = Shape::BOMB;
	}
	else {
		s.setShape(blockType);

		type = blockType;
	}
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			block[i][j] = ' ';
			block[i][j] = s.Shapes[blockType][j][i];

		}
	}
}
bool Block::rotateBolck(int n) {
	char  temp[BLOCKSIZE][BLOCKSIZE];
	char  Ttemp[BLOCKSIZE][BLOCKSIZE];//transopse

	if (s.getShape() == Shape::Shapes::cube)
	{
		return false;
	}

	for (size_t i = 0; i < BLOCKSIZE; i++)
	{ //Save temporarily block
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			temp[i][j] = block[i][j];
			block[i][j] = ' ';
		}
	}


	for (size_t i = 0; i < BLOCKSIZE; i++)
	{ //Rotate
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			Ttemp[i][j] = temp[j][i];
		}
	}
	if (n == 0) {
		for (size_t i = 0; i < BLOCKSIZE; i++)
		{ //Rotate
			for (size_t j = 0; j < BLOCKSIZE; j++)
			{
				block[i][3 - j] = Ttemp[i][j];
			}
		}
	}
	if (n == 1) {
		for (size_t i = 0; i < BLOCKSIZE; i++)
		{ //Rotate
			for (size_t j = 0; j < BLOCKSIZE; j++)
			{
				block[3 - i][j] = Ttemp[i][j];
			}
		}
	}
	fixBlock();

	if ((*board).isCollide(x, y))
	{ // And stop if it overlaps not be rotated
		for (size_t i = 0; i < BLOCKSIZE; i++)
		{
			for (size_t j = 0; j < BLOCKSIZE; j++)
			{
				block[i][j] = temp[i][j];
			}
		}
		return true;
	}
	return false;

}
void Block::spwanBlock()
{
	if (!(board->isCollide(x, (y + 1))))
	{
		board->removeBlock(getX(), (getY() + 1));
	}
	else
	{

		board->FixBoard();
		board->checkLine();
		board->addShape();
	}
}

void Block::fixBlock() {
	bool IsEmptyRow = true;
	bool IsEmptyCol = true;
	for (int i = 0; i < BLOCKSIZE; i++) {
		if (block[0][i] == '&')
			IsEmptyCol = false;

	}
	if (IsEmptyCol) {
		for (int i = 0; i < BLOCKSIZE; i++) {
			block[0][i] = block[1][i];
			block[1][i] = block[2][i];
			block[2][i] = block[3][i];
			block[3][i] = ' ';
		}
	}

	for (int i = 0; i < BLOCKSIZE; i++) {
		if (block[i][0] == '&')
			IsEmptyRow = false;

	}

	if (IsEmptyRow) {
		for (int i = 0; i < BLOCKSIZE; i++) {
			block[i][0] = block[i][1];
			block[i][1] = block[i][2];
			block[i][2] = block[i][3];
			block[i][3] = ' ';
		}
	}
}