#include "Menu.h"



int Menu::printMenu() {
	system("cls");
	gotoxy(x, y);
	cout << "THE TETRIS GAME!";
	gotoxy(x, y+2);
	cout << "Press -1- to Start" << endl;
	gotoxy(x, y +3);
	cout << "Press -2- to Resume" << endl;
	gotoxy(x, y + 4);
	cout << "Press -8- to Instrution" << endl;
	gotoxy(x, y + 5);
	cout << "Press -9- to Exit" << endl;
	
		int key = _getch();
		key = key - 48;
		if (key == 9) {
			system("cls");
			exit(2);
		}
		
		return key;
	

}
void Menu::printGameOver(int p){
	system("cls");
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