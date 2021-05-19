#include "Game.h"


int Game::run() {
	while (isGameOver() == 0) {

		Sleep(GAMESLEEP);
		
		userInput();
		if (!clearKeyboardBuffer()) {

			return 0;//chack for the ESC Key
		}
	}
	if (isGameOver() != 0) return isGameOver();
	return 0;
}

int Game::resume() {

	player_1->board.setPoint(Point(6, 5));
	player_2->board.setPoint(Point(48, 5));

	player_1->board.printboard(player_1->board.getPoint());
	player_1->board.display();
	player_2->board.printboard(player_2->board.getPoint());
	player_2->board.display();
	return run();
}






int Game::isGameOver() {

	if (player_1->board.getIsGameOVER())
		return 2;
	if (player_2->board.getIsGameOVER())
		return 1;
	return 0;
}



void Game::userInput() {

	char keySelction[2] = {};
	
	for (size_t i = 0; i < 10; i++) {
		if (_kbhit()) {
			char key = toupper(_getch());
			for (size_t j = 0; j < 5; j++) {
				if (key == player_1->board.getKey(j)) keySelction[0] = key;
				if (key == player_2->board.getKey(j)) keySelction[1] = key;
			}
		}
	}
	
	player_2->board.userInput(keyToDir(keySelction[1]));
	player_1->board.userInput(keyToDir(keySelction[0]));
	
	

}
int Game::keyToDir(char key) {
//enum DIR { LEFT = 0, RIGHT = 1, ROTATEL = 2, ROTATER = 3, DROP = 4, DOWN = 5 };
	for (int i= 0 ;i<= 5 ;i++)
	if (key == player_2->board.getKey(i)|| key == player_1->board.getKey(i)) {
		return i;
	}
	return DIR::DOWN;
}

int Game::HumenVsBotRun(int type) {
	int i = 0;
	BotPlayer* bp2 = static_cast<BotPlayer*>(player_2);
 	while (isGameOver() == 0) {
		char key = DIR::DOWN;
		Sleep(GAMESLEEP);
		if(_kbhit())
			 key = toupper(_getch());
	
		if (bp2->board.block.getX() == MID && bp2->board.block.getY() == UP) {
			i = 0;
			bp2->playerFlow(type);
		}
		if (bp2->getNextMove(i) != -1) {
			bp2->board.userInput(bp2->getNextMove(i));
			i++;
		}
		else
		{	
			bp2->playerFlow(type);
		}
		player_1->board.userInput(keyToDir(key));

		if (!clearKeyboardBuffer()) {

			return 0;//chack for the ESC Key
		}
	}
	if (isGameOver() != 0) return isGameOver();
	return 1;
}

int Game::botVsBotRun(int typeL,int typeR) {
	int i = 0;
	BotPlayer* bp2 = static_cast<BotPlayer*>(player_2);
	BotPlayer* bp1 = static_cast<BotPlayer*>(player_1);
	while (isGameOver() == 0) {
		char key = DIR::DOWN;
		Sleep(GAMESLEEP);

		if (bp2->board.block.getX() == MID && bp2->board.block.getY() == UP) {
			i = 0;
			bp2->playerFlow(typeL);
		}


		if (bp2->getNextMove(i) != -1) {
			bp2->board.userInput(bp2->getNextMove(i));
			i++;
		}
		else
		{
			bp2->playerFlow(typeL);
		}
		


		if (bp1->board.block.getX() == MID && bp1->board.block.getY() == UP) {
			i = 0;
			bp1->playerFlow(typeR);
		}
		if (bp1->getNextMove(i) != -1) {
			bp1->board.userInput(bp1->getNextMove(i));
			i++;
		}
		else
		{
			bp1->playerFlow(typeR);
		}

		if (!clearKeyboardBuffer()) {

			return 0;//chack for the ESC Key
		}
	}
	if (isGameOver() != 0) return isGameOver();
	return 1;
}

