#include "gotoxy.h"

#include <Windows.h>
#include <process.h>
using namespace std;

void gotoxy(size_t x, size_t y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void clrscr()
{
	system("cls");
}
bool clearKeyboardBuffer()
{
	char junk;
	while (_kbhit())
	{
		junk = _getch();
		if (junk == 27)//ESC key

			return false;
	}
	return true;
}
