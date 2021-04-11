#pragma once
#include "Player.h"
#include"Menu.h"
#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

class Game
{
	Player player_1;
	Player player_2;
	Menu menu;

public:
	void run();
	int isGameOver();

};

