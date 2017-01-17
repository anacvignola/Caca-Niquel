#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <string>
#include <cctype>
using namespace std;

void gotoxy(int x, int y) {
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int random() {
	return rand() % 5;
}

void screen(int x, int y, int qtd) {
	int aux = qtd;
	for (int i = 1; i < x; i++) {
		cout << "_";
		if (i > x - 2 && qtd > 1) {
			cout << "  ";
			i = 1;
			qtd--;
		}
	}
	qtd = aux;
	cout << endl;
	for (int i = 1; i < y; i++) {
		cout << "|";
		for (int k = 1; k < x - 2; k++)
			cout << " ";
		if (qtd > 1) {
			cout << "|" << "  " << "|";
			for (int k = 1; k < x - 3; k++)
				cout << " ";
		}
		cout << "|" << endl;
	}
	qtd = aux;
	cout << "|";
	for (int i = 1; i < x - 2; i++) {
		cout << "_";
		if (i > x - 4 && qtd > 1) {
			cout << "|" << "  " << "|";
			i = 1;
			qtd--;
		}
	}
	cout << "|" << endl;
}

void home() {

	system("cls");
	screen(60, 3, 1);
	screen(30, 7, 2);
	screen(60, 3, 1);
	gotoxy(21, 2); cout << "C A Ç A - N Í Q U E L" << endl << endl;
	gotoxy(11, 6); cout << "APOSTA" << endl;
	gotoxy(2, 8); cout << "Moedas de R$ 0,25: " << endl;
	gotoxy(12, 9); cout << "R$ 0,50: " << endl;
	gotoxy(12, 10); cout << "R$ 1,00: " << endl;
	gotoxy(42, 6); cout << "RODAS" << endl;
}
float totalaposta(){
	int coin;
	float total = 0;
	for (int i = 0; i < 3; i++) {
		do {
			gotoxy(21, i + 8);
			cin >> coin;
		} while (coin < 0);
		switch (i){
		case 0:
			total += coin*0.25;
			break;
		case 1:
			total += coin*0.50;
			break;
		default:
			total += coin*1.0;
			break;
		}

	}
	return total;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	home();

	int x, vec[4];
	float total;
	char r;
	string well[6] = { "$","#","#","@","@","@" };

	total = totalaposta();
	do {
		gotoxy(2, 14); cout << "Comfirmar aposta de R$" << total << " (S/N)? ";
		cin >> r;
	} while (toupper(r) != 'S' && toupper(r) != 'N');

	if (toupper(r) == 'S') {
		for (int i = 0; i < 3; i++) {
			x = random();
			vec[i] = x;
			gotoxy(i * 2 + 42, 8); cout << well[x];
		}
		if (well[vec[0]] == "$" || well[vec[1]] == "$" || well[vec[2]] == "$") {
			if (vec[0] == vec[1] && vec[0] == vec[2]) {
				total *= 30;
				gotoxy(2, 14); cout << "Parabéns! Você acabou de ganhar R$" << total << endl << endl << endl;
			}
			else if (vec[0] == vec[1] || vec[0] == vec[2] || vec[1] == vec[2]) {
				total *= 7;
				gotoxy(2, 14); cout << "Parabéns! Você acabou de ganhar R$" << total << endl << endl << endl;
			}
		}
		else if (well[vec[0]] == "#" || well[vec[1]] == "#" || well[vec[2]] == "#") {
			if (vec[0] == vec[1] && vec[0] == vec[2]) {
				total *= 5;
				gotoxy(2, 14); cout << "Parabéns! Você acabou de ganhar R$" << total << endl << endl << endl;
			}else if (vec[0] == vec[1] || vec[0] == vec[2] || vec[1] == vec[2]) {
				total *= 2;
				gotoxy(2, 14); cout << "Parabéns! Você acabou de ganhar R$" << total << endl << endl << endl;
			}
		}else {
			gotoxy(2, 14); cout << "Ops, não foi dessa vez..." << endl << endl << endl;
		}
	}else {
		return 0;
	}
	cout << endl << endl << endl;
	system("pause");
}
