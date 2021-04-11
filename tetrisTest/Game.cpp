#include "Game.h"
enum { DOWN = '0' };
enum { ESC = 27 };
void Game::run() {
	char c = 1;
	int key;
	key = menu.printMenu();
	_flushall();
	system("cls");
	char P1Keys[5] = { 'a','d','w','s','x' };
	char P2Keys[5] = { 'j','l','i','k','m' };

	while (key == 8) {
		menu.printInstruction();
		Sleep(800);
		key = menu.printMenu();

	}
	while (key == 1) {
		player_1.board.BoardInit(Point(6, 5), P1Keys);
		player_2.board.BoardInit(Point(48, 5), P2Keys);

		while (isGameOver() == 0 && _kbhit() != ESC) {

			Sleep(555);

			if (_kbhit()) {
				c = _getch();
				player_2.board.userInput(c);

				player_1.board.userInput(c);
				_flushall;
			}
			player_1.board.userInput(DOWN);
			player_2.board.userInput(DOWN);


		}
		system("cls");
		if(isGameOver())
		menu.printGameOver(isGameOver());
		player_1.board.setGameOver(false);
		player_2.board.setGameOver(false);
		_flushall;
		key = menu.printMenu();
		Sleep(5000);




	}

}







int Game::isGameOver() {

	if (player_1.board.getIsGameOVER())
		return 2;
	if (player_2.board.getIsGameOVER())
		return 1;
	return 0;
}
