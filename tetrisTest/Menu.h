#pragma once
#include <iostream>
#include<conio.h>
#include"gotoxy.h"
#include <windows.h>

#include "Board.h"
#include "Game.h"

using namespace std;
class Menu
{
	
	int x=20;
	int y=10;

public:
	void printMenu();
	void printGameOver(int P,Game& game);
	void printInstruction();
	int choseTypeBot();

};

