#include "Game.h"
enum { DOWN = '0' };
enum { ESC = 27 };

int Game::run() {
	while (isGameOver() == 0) {

		Sleep(555);

		
		
		

		player_1.board.userInput(DOWN);
		player_2.board.userInput(DOWN);
		userInput();
		if (!clearKeyboardBuffer()) {

			return 0;//chack for the ESC Key
		}



	}
	if (isGameOver() != 0) return isGameOver();
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
	char temp;
	char c1, c2;
	c2 = c1 = '0';

	for (size_t i = 0; i < 10; i++) {
		if (_kbhit()) {
			temp = _getch();

			for (size_t j = 0; j < 5; j++) {
				if (temp == player_1.board.getKey(j) || temp == player_1.board.getKey(j) - 32) c1 = temp;
				if (temp == player_2.board.getKey(j) || temp == player_2.board.getKey(j) - 32) c2 = temp;
			}
		}
	}
	player_2.board.userInput(c2);
	player_1.board.userInput(c1);

}