#pragma once

#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "BotPlayer.h"


enum DIR { LEFT = 0, RIGHT = 1, ROTATEL = 2, ROTATER = 3, DROP = 4, DOWN = 5 };

class Game
{
	Player* player_1 = nullptr;
	Player* player_2=nullptr;


	enum { DOWN = 0 };
	enum { ESC = 27 };
	enum { GAMESLEEP = 700 };
public:
	Game(char type) {
		
		player_1 = new Player;
		player_2 = new Player;


	
		if (type == '2') {
			player_2 = new BotPlayer;
			
		}
		if (type == '3') {
			player_1 = new BotPlayer;
			player_2 = new BotPlayer;
		}
	}


	int  run();
	int isGameOver();
	void userInput();
	int resume();
	int keyToDir(char key);
	int HumenVsBotRun();
	friend class Menu;

};

