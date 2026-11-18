#include <iostream>
#include <windows.h>
#include <conio.h>

//realice un programa que dibuje con gotoxy y bluces un rectangulo de 40 x 15 caracteres y coloque una letra x en su centro. la letra se mueve con las flechas del tecldo usando getch
//(las flechas llegan en dos partes 224 y luego 72, 80, 75, 77) borrando su posicion anterior y sin atravesar los bordes.
//muestre la posicion de la letra debajo del rectangulo. la tecla esc termina el programa

using namespace std;

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

int main() {
	int x = 30, y = 10;
	
	for(int i = 20; i <= 60; i++) {
		gotoxy(i, 5);
		cout<<"*";
		gotoxy(i, 20);
		cout<<"*";
	}
	for(int i = 5; i <= 20; i++) {
		gotoxy(20, i);
		cout<<"*";
		gotoxy(60, i);
		cout<<"*";
	}

	while(true) {
		gotoxy(x, y);
		cout<<"X";
		gotoxy(20, 22);
		cout<<"X:"<<x<<" Y:"<<y<<"   ";

		int t = _getch();
		if(t == 27) break;
		if(t == 224) {
			int d = _getch();
			gotoxy(x, y);
			cout<<" ";
			if(d == 72 && y > 6) y--;
			if(d == 80 && y < 19) y++;
			if(d == 75 && x > 21) x--;
			if(d == 77 && x < 59) x++;
		}
	}
	return 0;
}
