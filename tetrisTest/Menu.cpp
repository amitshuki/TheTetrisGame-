#include "Menu.h"



void Menu::printMenu() {
	char key = -1;
	int p=0;
	bool firstrun = false;
	while (key != 9) {
		
		system("cls");
		gotoxy(x, y);
		cout << "THE TETRIS GAME!";
		gotoxy(x, y + 2);
		cout << "Press -1- to Start" << endl;
		gotoxy(x, y + 3);
		cout << "Press -2- to Resume" << endl;
		gotoxy(x, y + 4);
		cout << "Press -8- to Instrution" << endl;
		gotoxy(x, y + 5);
		cout << "Press -9- to Exit" << endl;
		key = _getch();
		Game game;
		char P1Keys[5] = { 'a','d','w','s','x' };
		char P2Keys[5] = { 'j','l','i','k','m' };
		
		system("cls");
		switch (key) {
		case '1':
			game.player_1.board.BoardInit(Point(6, 5), P1Keys);
			game.player_2.board.BoardInit(Point(48, 5), P2Keys);
			p=game.run();
			firstrun = true;
			printGameOver(p);
			break;
		case '2':
			if (firstrun == true && (p==0)) {//if this is not the first game before run and if we get push from run
				p = game.resume();
				printGameOver(p);
			}
		
			break;
		case '8':
			printInstruction();
			break;
		case '9':
			return;
		}
		
	}
}


void Menu::printGameOver(int p){
	if (p == 1 || p == 2) {
		
		game.player_1.board.setGameOver(false);
		game.player_2.board.setGameOver(false);
		system("cls");
		gotoxy(0, 7);
		cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
		cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
		cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
		cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
		cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
		cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
		cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
		cout << "\n\n PLAYER " << p << " WON!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
		Sleep(5000);

	}

	
}



void Menu::printInstruction()
{
	char c = 'a';
	system("cls");
	while (c != 27) {
		
		cout << "INSTRUCTIONS : " << endl;
		gotoxy(0, 5); cout << "Left  "; gotoxy(6 + ROWS, 5); cout << "a or A"; gotoxy(48, 5); cout << "j or J";
		gotoxy(0, 6); cout << "Right  "; gotoxy(6 + ROWS, 6); cout << "d or D"; gotoxy(48, 6); cout << "l or L";
		gotoxy(0, 7); cout << "ROTATE clockwise  "; gotoxy(6 + ROWS, 7); cout << "s or S"; gotoxy(48, 7); cout << "k or K";
		gotoxy(0, 8); cout << "ROTATE counterclockwise  "; gotoxy(6 + ROWS, 8); cout << "w or W"; gotoxy(48, 8); cout << "i or I";
		gotoxy(0, 9); cout << "DROP  "; gotoxy(6 + ROWS, 9); cout << "x or X"; gotoxy(48, 9); cout << "m or M";
		cout << endl << "ESC TO CONTINUE" << endl;
		c = _getch();
	}
	system("cls");
	
	
}