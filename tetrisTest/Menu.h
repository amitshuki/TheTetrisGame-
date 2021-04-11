#pragma once
#include <iostream>
#include<conio.h>
#include"gotoxy.h"
#include <windows.h>
#include "Board.h"

using namespace std;
class Menu
{
	int x=20;
	int y=10;

public:
	int printMenu();
	void printGameOver(int P);
	char printInstruction();

};

