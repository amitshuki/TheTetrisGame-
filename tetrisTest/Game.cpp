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
	return 1;
}

int Game::resume() {

	player_1.board.setPoint(Point(6, 5));
	player_2.board.setPoint(Point(48, 5));

	player_1.board.printboard(player_1.board.getPoint());
	player_1.board.display();
	player_2.board.printboard(player_2.board.getPoint());
	player_2.board.display();
	return run();
}






int Game::isGameOver() {

	if (player_1.board.getIsGameOVER())
		return 2;
	if (player_2.board.getIsGameOVER())
		return 1;
	return 0;
}



void Game::userInput() {

	char keySelction[2] = {};
	
	for (size_t i = 0; i < 10; i++) {
		if (_kbhit()) {
			char key = toupper(_getch());
			for (size_t j = 0; j < 5; j++) {
				if (key == player_1.board.getKey(j)) keySelction[0] = key;
				if (key == player_2.board.getKey(j)) keySelction[1] = key;
			}
		}
	}
	player_2.board.userInput(keySelction[1]);
	player_1.board.userInput(keySelction[0]);

}