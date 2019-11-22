#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

void createField(char field[5][5])
{
	int j = 0;
	for (int i = 0;i < 5;i++)
		for (j = 0;j < 5;j++) {
			if ((i == 0) || (i == 4))
				field[i][j] = '#';
			else if ((j == 0) || (j == 4))
				field[i][j] = '#';
			else
				field[i][j] = ' ';
		}
}

void showField(char field[5][5])
{
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cout << field[i][j];
		}
		cout << endl;
	}
}
int inputX(char field[5][5])
{
	int x, y;
	cout << "ÂÎÑÏÎËÜÇÓÉÒÅÑÜ NUM LK" << endl << endl;
	//cout << "EXIT (ÍÀÆÌÈÒÅ ÍÀ '0')" << endl;
	do {
		y = 10; x = 10;
		switch (_getch()) {
		case '1':
			if (field[3][1] == ' ') {
				x = 3;
				y = 1;
			}
			break;
		case '2':
			if (field[3][2] == ' ') {
				x = 3;
				y = 2;
			}
			break;
		case '3':
			if (field[3][3] == ' ') {
				x = 3;
				y = 3;
			}
			break;
		case '4':
			if (field[2][1] == ' ') {
				x = 2;
				y = 1;
			}
			break;
		case '5':
			if (field[2][2] == ' ') {
				x = 2;
				y = 2;
			}
			break;
		case '6':
			if (field[2][3] == ' ') {
				x = 2;
				y = 3;
			}
			break;
		case '7':
			if (field[1][1] == ' ') {
				x = 1;
				y = 1;
			}
			break;
		case '8':
			if (field[1][2] == ' ') {
				x = 1;
				y = 2;
			}
			break;
		case '9':
			if (field[1][3] == ' ') {
				x = 1;
				y = 3;
			}
			break;
		}
	} while ((field[x][y] == 'X') || (field[x][y] == 'O') || (y == 10));
	field[x][y] = 'X';
	return x;
}
int inputXX(char field[5][5])
{
	int x, y;
	cout << "ÂÎÑÏÎËÜÇÓÉÒÅÑÜ NUM LK" << endl << endl;
	//cout << "EXIT (ÍÀÆÌÈÒÅ ÍÀ '0')" << endl;
	do {
		y = 10; x = 10;
		switch (_getch()) {
		case '1':
			if (field[3][1] == ' ') {
				x = 3;
				y = 1;
			}
			break;
		case '2':
			if (field[3][2] == ' ') {
				x = 3;
				y = 2;
			}
			break;
		case '3':
			if (field[3][3] == ' ') {
				x = 3;
				y = 3;
			}
			break;
		case '4':
			if (field[2][1] == ' ') {
				x = 2;
				y = 1;
			}
			break;
		case '5':
			if (field[2][2] == ' ') {
				x = 2;
				y = 2;
			}
			break;
		case '6':
			if (field[2][3] == ' ') {
				x = 2;
				y = 3;
			}
			break;
		case '7':
			if (field[1][1] == ' ') {
				x = 1;
				y = 1;
			}
			break;
		case '8':
			if (field[1][2] == ' ') {
				x = 1;
				y = 2;
			}
			break;
		case '9':
			if (field[1][3] == ' ') {
				x = 1;
				y = 3;
			}
			break;
		}
	} while ((field[x][y] == 'X') || (field[x][y] == 'O') || (y == 10));
	field[x][y] = 'O';
	return x;
}
void inputO(char field[5][5])
{
	int x, y;
	do {
		int count;
		// ïðîâåðêà íà âûéãðûø ãîðèçîíòàëü
		for (int j = 1; j < 4; j++) {
			count = 0;
			for (int i = 1; i < 4; i++) {
				if (field[j][i] == ' ') {
					x = j;
					y = i;
				}
				if (field[j][i] == 'O')
					count = count + 1;
				if (field[j][i] == 'X')
					count = count + 3;
			}
			if (count == 2) {
				break;
			}
		}
		if (count == 2)
			break;
		// ïðîâåðêà íà âûéãðûø âåðòèêàëü
		for (int i = 1; i < 4; i++) {
			count = 0;
			for (int j = 1; j < 4; j++) {
				if (field[j][i] == ' ') {
					x = j;
					y = i;
				}
				if (field[j][i] == 'O')
					count = count + 1;
				if (field[j][i] == 'X')
					count = count + 3;
			}
			if (count == 2) {
				break;
			}
		}
		if (count == 2)
			break;
		// ïðîâåðêà íà âûéãðûø ïî âåðòèêàëè /
		count = 0;
		for (int i = 1; i < 4; i++) {
			if (field[i][i] == ' ') {
				x = i;
				y = i;
			}
			if (field[i][i] == 'O')
				count++;
			if (field[i][i] == 'X')
				count = count + 3;
		}
		if (count == 2)
			break;
		// ïðîâåðêà íà âûéãðûø ïî äðóãîé âåðòèêàëè /
		int j;
		j = 3;
		for (int i = 1; i < 4; i++) {
			if (field[i][j] == ' ') {
				x = i;
				y = j;
			}
			if (field[i][j] == 'X')
				count = count + 3;
			if (field[i][j] == 'O')
				count++;
			j--;
		}
		if (count == 2)
			break;
		//åñëè â ñòðîêå 2 èêñà, òî ñòàâèòüñÿ O
		for (int j = 1; j < 4; j++) {
			count = 0;
			for (int i = 1; i < 4; i++) {
				if (field[j][i] == 'X')
					count = count + 1;
				if (field[j][i] == ' ')
					y = i;
				if (field[j][i] == 'O')
					count = count + 3;
			}
			if (count == 2) {
				x = j;
				break;
			}
		}
		if (count == 2)
			break;
		x = 0;y = 0;
		//åñëè â ñòîëáöå 2 èêñà, òî ñòàâèòüñÿ O
		for (int i = 1; i < 4; i++) {
			count = 0;
			int j;
			for (j = 1; j < 4; j++) {
				if (field[j][i] == 'X')
					count = count + 1;
				if (field[j][i] == ' ') {
					y = i; x = j;
				}
				if (field[j][i] == 'O')
					count = count + 3;
			}
			if (count == 2) {
				break;
			}
		}
		if (count == 2)
			break;
		//åñëè ïî äèàãîíàëå 2 èêñà, òî ñòàâèòüñÿ O
		count = 0;
		for (int i = 1; i < 4; i++) {
			if (field[i][i] == ' ') {
				x = i;
				y = i;
			}
			if (field[i][i] == 'X')
				count++;
		}
		if (count == 2)
			break;
		//åñëè ïî äðóãîé äèàãîíàëå 2 èêñà, òî ñòàâèòüñÿ O
		count = 0;
		j = 3;
		for (int i = 1; i < 4; i++) {
			if (field[i][j] == ' ') {
				x = i;
				y = j;
			}
			if (field[i][j] == 'X')
				count++;
			j--;
		}
		if (count == 2)
			break;
		if (field[2][2] == ' ') {
			x = 2;y = 2;
			break;
		}
		if (field[1][1] == ' ') {
			x = 1;y = 1;
			break;
		}
		if (field[3][3] == ' ') {
			x = 3;y = 3;
			break;
		}
		if (field[3][1] == ' ') {
			x = 3;y = 1;
			break;
		}
		if (field[1][3] == ' ') {
			x = 1;y = 3;
			break;
		}
		x = 1 + rand() % 3;
		y = 1 + rand() % 3;
	} while ((field[x][y] == 'X') || (field[x][y] == 'O'));
	field[x][y] = 'O';
}
int logic(char field[5][5])
{
	int count = 0;
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++)
			if (field[i][j] != ' ')
				count++;
		if (count == 9)
			return 3;
	}
	for (int i = 1; i < 4; i++) {
		if ((field[i][1] == 'X') && (field[i][2] == 'X') && (field[i][3] == 'X')) {
			return 1;
		}
		if ((field[i][1] == 'O') && (field[i][2] == 'O') && (field[i][3] == 'O')) {
			return 2;
		}
	}
	for (int i = 1; i < 4; i++) {
		if ((field[1][i] == 'X') && (field[2][i] == 'X') && (field[3][i] == 'X')) {
			return 1;
		}
		else if ((field[1][i] == 'O') && (field[2][i] == 'O') && (field[3][i] == 'O')) {
			return 2;
		}
	}
	if ((field[1][1] == 'X') && (field[2][2] == 'X') && (field[3][3] == 'X')) {
		return 1;
	}
	else if ((field[1][1] == 'O') && (field[2][2] == 'O') && (field[3][3] == 'O')) {
		return 2;
	}
	if ((field[3][1] == 'X') && (field[2][2] == 'X') && (field[1][3] == 'X')) {
		return 1;
	}
	else if ((field[3][1] == 'O') && (field[2][2] == 'O') && (field[1][3] == 'O')) {
		return 2;
	}
	return 4;
}
void main()
{
	srand(time(0));
	setlocale(0, "");
	char field[5][5];
	char znak;
	int k, log, o;
	o = 2;
	log = 4;
	do {
		createField(field);
		cout << "ÈÃÐÀ ÊÐÅÑÒÈÊÈ-ÍÎËÈÊÈ" << endl << endl;
		cout << "ÈÃÐÀÒÜ ÂÄÂÎ¨Ì" << "\t\t\t(ÍÀÆÌÈÒÅ 1)" << endl;
		cout << "ÈÃÐÀÒÜ ÏÐÎÒÈÂ ÐÎÁÎÒÀ 'PAUL'" << "\t(ÍÀÆÌÈÒÅ 2)" << endl;
		cin >> o;
		if (o == 1) {
			system("cls");
			showField(field);
			do {
				if (inputX(field) == 0)
					break;
				system("cls");
				showField(field);
				log = logic(field);
				if (log == 1) {
					cout << "ÏÅÐÂÛÉ ÈÃÐÎÊ ÏÎÁÅÄÈË 'X' " << endl;
					break;
				}
				if (log == 2) {
					cout << "ÂÒÎÐÎÉ ÈÃÐÎÊ ÏÎÁÅÄÈË 'Y' " << endl;
					break;
				}
				if (log == 3) {
					cout << "ÍÈ×Üß !" << endl;
					break;
				}
				if (inputXX(field) == 0)
					break;
				system("cls");
				showField(field);
				log = logic(field);
				if (log == 1) {
					cout << "ÏÅÐÂÛÉ ÈÃÐÎÊ ÏÎÁÅÄÈË 'X' " << endl;
					break;
				}
				if (log == 2) {
					cout << "ÂÒÎÐÎÉ ÈÃÐÎÊ ÏÎÁÅÄÈË 'Y' " << endl;
					break;
				}
				if (log == 3) {
					cout << "ÍÈ×Üß !" << endl;
					break;
				}
			} while (log == 4);
			cout << "ÂÅÐÍÓÒÜÑß Â MENU (ÍÀÆÌÈÒÅ ÍÀ ËÞÁÓÞ ÊËÀÂÈØÓ)" << endl;
			_getch();
			system("cls");
		}
		if (o == 2) {
			cout << "ÁÓÄÅÒÅ ÕÎÄÈÒÜ ÏÅÐÂÛÅ ÈËÈ ÂÒÎÐÛÅ?" << "(ÍÀÆÌÈÒÅ ÍÀ 1 ÈËÈ 2)" << endl;
			cin >> k;
			system("cls");
			showField(field);
			if (k == 1) {
				do {
					if (inputX(field) == 0)
						break;
					system("cls");
					showField(field);
					log = logic(field);
					if (log == 1) {
						cout << "ÏÅÐÂÛÉ ÈÃÐÎÊ ÏÎÁÅÄÈË 'X' " << endl;
						break;
					}
					if (log == 2) {
						cout << "ÂÒÎÐÎÉ ÈÃÐÎÊ ÏÎÁÅÄÈË 'Y' " << endl;
						break;
					}
					if (log == 3) {
						cout << "ÍÈ×Üß !" << endl;
						break;
					}
					cout << "Äàé ïîäóìàòü:) " << endl;
					Sleep(2000);
					system("cls");
					inputO(field);
					showField(field);
					log = logic(field);
					if (log == 1) {
						cout << "ÏÅÐÂÛÉ ÈÃÐÎÊ 'X' ÏÎÁÅÄÈË" << endl;
						break;
					}
					if (log == 2) {
						cout << "ÂÒÎÐÎÉ ÈÃÐÎÊ 'O' ÏÎÁÅÄÈË" << endl;
						break;
					}
					if (log == 3) {
						cout << "ÍÈ×Üß !" << endl;
						break;
					}
				} while (log == 4);
			}
			else if (k == 2) {
				do {
					cout << "Äàé ïîäóìàòü:) " << endl;
					Sleep(2000);
					inputO(field);
					system("cls");
					showField(field);
					log = logic(field);
					if (log == 1) {
						cout << "ÏÅÐÂÛÉ ÈÃÐÎÊ 'X' ÏÎÁÅÄÈË" << endl;
						break;
					}
					if (log == 2) {
						cout << "ÂÒÎÐÎÉ ÈÃÐÎÊ 'O' ÏÎÁÅÄÈË" << endl;
						break;
					}
					if (log == 3) {
						cout << "ÍÈ×Üß !" << endl;
						break;
					}
					inputX(field);
					system("cls");
					showField(field);
					log = logic(field);
					if (log == 1) {
						cout << "ÏÅÐÂÛÉ ÈÃÐÎÊ 'X' ÏÎÁÅÄÈË" << endl;
						break;
					}
					if (log == 2) {
						cout << "ÂÒÎÐÎÉ ÈÃÐÎÊ 'O' ÏÎÁÅÄÈË" << endl;
						break;
					}
					if (log == 3) {
						cout << "ÍÈ×Üß !" << endl;
						break;
					}
				} while (log == 4);
			}
			cout << "ÂÅÐÍÓÒÜÑß Â MENU (ÍÀÆÌÈÒÅ ÍÀ ËÞÁÓÞ ÊËÀÂÈØÓ)" << endl;
			_getch();
			system("cls");
		}
	} while (0 == 0);
}