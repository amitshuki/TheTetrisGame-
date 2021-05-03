#include "Board.h"


void Board::printboard(Point p)
{
	for (size_t i = p.getX() - 1; i < COLS + p.getX() + 1; i++) {
		for (size_t j = p.getY(); j < ROWS + p.getY() + 1; j++) {

			if (i == p.getX() - 1 || i == p.getX() + COLS) {
				gotoxy(i, j);
				cout << wall;
			}
			if (j == p.getY() + ROWS) {
				gotoxy(i, j);
				cout << floor;
			}
		}
	}
}

void Board::display()
{
	size_t y = point.getY();// cahseing
	size_t x = point.getX();// cahseing

	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++) {
			gotoxy(x + i, y + j);
			if (boardGame[i][j] == '&')
				cout << '#';
			else
				cout << boardGame[i][j];
		}
	}
}

void Board::BoardInit(Point _p, char* _keys) {
	point.setX(_p.getX());
	point.setY(_p.getY());
	block.board = this;//for the forward declaration

	for (size_t i = 0; i < 5; i++) {
		Keys[i] = _keys[i];
	}

	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++) {

			boardGame[i][j] = ' ';
		}
	}
	this->printboard(_p);
	this->addShape();
	this->display();

}

void Board::addShape() {
	block.updateblock();

	if (isCollide(block.getX(), (block.getY() + 1))) {
		isgameOver = true;
		return;
	}

	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			char c = block.getBlockChar(i, j);
			boardGame[i + 5][j] = c;
		}
	}

}

void Board::removeBlock(int _x, int _y)
{
	 const int x = block.getX();
	 const int y = block.getY();
	//Remove block
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (boardGame[x + i][(y + j)] == '&')
				boardGame[x + i][(y + j)] = ' ';


		}
	}


	//Update coordinates
	block.setX(_x);
	block.setY(_y);
	collide();

}




bool Board::isCollide(int x, int y)
{
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if ('&' == block.getBlockChar(i,j))
			{
				if (boardGame[x + i][y + j] == '#' || x < 0 || x + i  == COLS || y + j == ROWS)
					return true;
			}
		}
	}
	return false;
}

void Board::userInput(char key)
{

	if (key == Keys[0]) {
		if (!isCollide(block.getX() - 1, block.getY()) && isInBoard(block.getX() - 1, block.getY()))
		{
			removeBlock(block.getX() - 1, block.getY());

		}
	}

	else if (key == Keys[1]) {
		if (!isCollide(block.getX() + 1, block.getY()) && isInBoard(block.getX() + 1, block.getY()))
		{
			removeBlock((block.getX() + 1), block.getY());

		}
	}
	else if (key == Keys[4]) {
		while (!isCollide(block.getX(), block.getY() + 1) && isInBoard(block.getX(), block.getY() + 1))
		{

			removeBlock(block.getX(), block.getY() + 1);
			
		}

		block.spwanBlock();

	}
	else if (key == Keys[3])
		block.rotateBolck(0);

	else if (key == Keys[2])
		block.rotateBolck(1);


	else if (key == 0) {


		if (!isCollide(block.getX(), block.getY() + 1) && isInBoard(block.getX(), block.getY() + 1))
		{
			removeBlock(block.getX(), block.getY() + 1);

			if (block.getY() == (ROWS + 1) || isCollide(block.getX(), block.getY() + 1))
				block.spwanBlock();
		}
	}
	display();

}

void Board::clearBlock() {
	for (size_t i = 0; i < BLOCKSIZE; i++) {
		for (size_t j = 0; j < BLOCKSIZE; j++) {
			if (block.getBlockChar(i, j) == '&')
				block.SetBlockChar(i, j, ' ');
		}
	}
}






bool Board::isInBoard(int x, int y) {

	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if ((x + i) < COLS && (y + j) < ROWS) {
				if (boardGame[x + i][y + j] == ' ') {
					return true;
				}
			}
		}
	}
	return false;
}

void Board::FixBoard() {
	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++) {
			if (boardGame[i][j] == '&') {
				boardGame[i][j] = '#';
			}
			
		}
	}
}

void Board::collide() {
	int _x = block.getX();
	int _y = block.getY();
	
	for (size_t i = 0; i < BLOCKSIZE; i++)
	{
		for (size_t j = 0; j < BLOCKSIZE; j++)
		{
			if (block.getBlockChar(i, j) == '&')
				boardGame[(_x + i)][(_y + j)] = block.getBlockChar(i, j);
		}

	}

}


void Board::checkLine()
{
	for (size_t j = 0; j < ROWS; j++)
	{

		int counter = 0;

		for (size_t i = 0; i < COLS; i++) {
			if (boardGame[i][j] == ' ')
				break;
			else
				counter++;

			if (counter == COLS)
			{
				deleteLine(j);
				refreshLines(j);
			}
		}
	}
}

void Board::deleteLine(int col)
{
	for (size_t i = 0; i < COLS; i++)
	{
		boardGame[i][col] = ' ';
	}
}


void Board::refreshLines(int col)
{


	for (size_t i = col; i > 1; i--)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			boardGame[j][i] = boardGame[j][i - 1];
		}
	}
}


void Board::setKeys(char* key) {
	for (size_t i = 0; i < 5; i++) {
		Keys[i] = key[i];
	}
}



