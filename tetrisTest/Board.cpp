#include "Board.h"


void Board::printboard(Point p) {


	for (int i = p.getX() - 1; i < COLS + p.getX() + 1; i++) {
		for (int j = p.getY(); j < ROWS + p.getY() + 1; j++) {

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

void Board::display() {

	int y = point.getY();// cahseing
	int x = point.getX();// cahseing
	gotoxy(x, y - 1);
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
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

	for (size_t i = 0; i < 5; i++) {
		Keys[i] = _keys[i];
	}

	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {

			boardGame[i][j] = ' ';
		}
	}
	this->printboard(_p);
	this->addShape();
	this->display();

}

void Board::addShape() {
	int blockType = rand() % 7;
	x = MID;
	y = UP;
	s.setShape(blockType);
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			block[i][j] = ' ';
			block[i][j] = s.Shapes[blockType][j][i];

		}

	}

	if (isCollide(x, y + 1)) {
		isgameOver = true;
		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			boardGame[i + 5][j] = block[i][j];
		}
	}

}

void Board::moveBlock(int _x, int _y)
{

	//Remove block
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{

			if (boardGame[x + i][y + j] == '&')
				boardGame[x + i][y + j] = ' ';


		}
	}


	//Update coordinates
	x = _x;
	y = _y;
	collide();

}

bool Board::rotateBolck(int n)
{
	char  temp[4][4];
	char  Ttemp[4][4];//transopse

	if (s.getShape() == Shape::Shapes::cube)
	{
		return false;
	}

	for (size_t i = 0; i < 4; i++)
	{ //Save temporarily block
		for (size_t j = 0; j < 4; j++)
		{
			temp[i][j] = block[i][j];
			block[i][j] = ' ';
		}
	}


	for (size_t i = 0; i < 4; i++)
	{ //Rotate
		for (size_t j = 0; j < 4; j++)
		{
			Ttemp[i][j] = temp[j][i];
		}
	}
	if (n == 0) {
		for (size_t i = 0; i < 4; i++)
		{ //Rotate
			for (size_t j = 0; j < 4; j++)
			{
				block[i][3 - j] = Ttemp[i][j];
			}
		}
	}
	if (n == 1) {
		for (size_t i = 0; i < 4; i++)
		{ //Rotate
			for (size_t j = 0; j < 4; j++)
			{
				block[3 - i][j] = Ttemp[i][j];
			}
		}
	}

	if (isCollide(x, y))
	{ // And stop if it overlaps not be rotated
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				block[i][j] = temp[i][j];
			}
		}
		return true;
	}
	return false;

}


bool Board::isCollide(int x, int y)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (block[i][j] == '&')
			{
				if (boardGame[x + i][y + j] == '#' || x < 0 || x + i == COLS || y + j == ROWS)
					return true;
			}
		}
	}
	return false;
}

void Board::userInput(char key)
{
	int diff = 'a' - 'A';

	if (key == Keys[0] || key == Keys[0] - diff) {
		if (!isCollide(x - 1, y) && isInBoard(x - 1, y))
		{
			moveBlock(x - 1, y);

		}
	}

	else if (key == Keys[1] || key == Keys[1] - diff) {
		if (!isCollide(x + 1, y) && isInBoard(x + 1, y))
		{
			moveBlock(x + 1, y);

		}
	}

	else if (key == Keys[4] || key == Keys[4] - diff) {
		while (!isCollide(x, y + 1) && isInBoard(x, y + 1))
		{

			moveBlock(x, y + 1);

		}

		spwanBlock();

	}
	else if (key == Keys[3] || key == Keys[3] - diff)
		rotateBolck(0);

	else if (key == Keys[2] || key == Keys[2] - diff)
		rotateBolck(1);


	else if (key == '0') {


		if (!isCollide(x, y + 1) && isInBoard(x, y + 1))
		{
			moveBlock(x, y + 1);

			if (y == ROWS + 1 || isCollide(x, y + 1))
				spwanBlock();
		}
	}
	display();
	_flushall;
}



void Board::spwanBlock()
{
	if (!isCollide(x, y + 1))
	{
		moveBlock(x, y + 1);
	}
	else
	{

		FixBoard();
		checkLine();
		addShape();
	}
}



bool Board::isInBoard(int x, int y) {

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
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
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (boardGame[i][j] == '&') {
				boardGame[i][j] = '#';
			}
		}
	}
}

void Board::collide() {

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (block[i][j] != ' ')
				boardGame[x + i][y + j] = block[i][j];
		}

	}

}


void Board::checkLine()
{
	for (int j = 0; j < ROWS; j++)
	{

		int counter = 0;

		for (int i = 0; i < COLS; i++) {
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
	for (int i = 0; i < COLS; i++)
	{
		boardGame[i][col] = ' ';
	}
}


void Board::refreshLines(int col)
{
	int counter = 0;

	for (int i = col + 1; i <= 0; i--)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (boardGame[i][j] != ' ')
			{
				boardGame[j][i - 1] = boardGame[j][i];
				boardGame[j][i] = ' ';
			}
			else
				counter++;
		}
		if (counter == COLS)
			return;
	}
}






