#include<iostream>
using namespace std;

char Matrix[3][3] = { '1','2', '3','4', '5','6', '7','8', '9'};
char Player = 'X';
void PrintMatrix() {
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Matrix[i][j] << "   ";
		}
		cout << endl;
	}
}
void Play() {
	char pos;
	cout << "Choes Your Position - Player (" << Player << ") ";
	cin >> pos;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Matrix[i][j] == pos) {
				Matrix[i][j] = Player;
			}
		}
	}

	if (Player == 'X')
		Player = 'O';
	else
	{
		Player = 'X';
	}
}
char WhoWin() {
	int Xc = 0, Oc = 0;
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Matrix[i][j] != 'X' && Matrix[i][j] != 'O') counter++;
			if (Matrix[i][j] == 'X') Xc++;
			else if (Matrix[i][j] == 'O') Oc++;

			if (Xc == 3 || Oc == 3) {
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0;
		Oc = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Matrix[j][i] == 'X') Xc++;
			else if (Matrix[j][i] == 'O') Oc++;
			if (Xc == 3 || Oc == 3) {
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0;
		Oc = 0;
		if (Matrix[0][0] == 'X' & Matrix[1][1] == 'X' & Matrix[2][2] == 'X') return 'X';
		if (Matrix[0][0] == 'O' & Matrix[1][1] == 'O' & Matrix[2][2] == 'O') return 'O';
		if (Matrix[0][2] == 'X' & Matrix[1][1] == 'X' & Matrix[2][0] == 'X') return 'X';
		if (Matrix[0][0] == 'O' & Matrix[1][1] == 'O' & Matrix[2][2] == 'O') return 'O';
		if (counter == 0) return 'Z';
	}
	return '.';
}

int main()
{
	while (WhoWin() == '.'){
		PrintMatrix();
		Play();
	}	
	PrintMatrix();
	if (WhoWin() == 'Z')
		cout << "\nNo Winner !! \n\n" << endl;
	else
		cout << "\nThe Winner Is Player(" << WhoWin() << ") , Congratulation !! \n\n";

	system("pause");
}

