#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

char menu[9] = { '1','2','3','4','5','6','7','8','9' }, changer = 'X';
int choice, counter = 1, lc, fc, a;
string name1, name2, adm, adm1, input, pass;
bool draw = false;
void twoply();
void singleplayer();
bool gameover();
int notcenter();
int winning();
void Admin();
void table() {
	cout << setw(68) << "     |     |     " << endl;
	cout << setw(53) << "  " << menu[0] << "  |  " << menu[1] << "  |  " << menu[2] << "  " << endl;
	cout << setw(68) << "_____|_____|_____" << endl;
	cout << setw(68) << "     |     |     " << endl;
	cout << setw(53) << "  " << menu[3] << "  |  " << menu[4] << "  |  " << menu[5] << "  " << endl;
	cout << setw(68) << "_____|_____|_____" << endl;
	cout << setw(68) << "     |     |     " << endl;
	cout << setw(53) << "  " << menu[6] << "  |  " << menu[7] << "  |  " << menu[8] << "  " << endl;
	cout << setw(68) << "     |     |     " << endl;
}

int main() {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	while (true) {
		while (true) {
			char inp;
			cout << "\t\t\t\tWELCOME TO TIC TAC TOE GAME!!!!\n" << endl;
			cout << "\t[1] :- GAME" << setw(65) << "[2] :- ADMIN" << setw(65) << "[3] :- EXIT" << endl;
			cout << "Enter:- ";
			cin >> a;
			if (a == 2) {
				Admin();
			}
			else if (a == 1) {
				while (true) {
					if (a == 400) {
						break;
					}
					else {
						system("CLS");
						cout << "\t\t\t\t\t    " << "T I C --- T A C --- T O E --- G A M E" << endl;
						cout << "\n\n" << setw(40) << "VS COMPUTER" << setw(55) << "VS PLAYER" << endl;
						cout << setw(36) << "[1]" << setw(58) << "[2]\n\n" << endl;
						cout << setw(50) << "HIGH SCORES";
						cout << setw(34) << "BACK TO MENU" << endl;
						cout << setw(46) << "[H]";
						cout << setw(35) << "[B]\n\n" << endl;
						cout << setw(64) << "END GAME" << endl;
						cout << setw(64) << " [E]\n\n\n" << endl;
						table();
						cout << "Enter the choice: ";
						cin >> inp;
						switch (inp) {
						case '1':
							cout << "Enter player's name: ";
							getline(cin >> ws, ::name1);
							while (gameover()) {
								singleplayer();
								system("CLS");
								table();
							}
							if (draw == true)
								cout << "\n\t\t\t\tMatch Draw!!!!!!" << endl;
							else {
								if (changer == 'O')
									cout << "CONGRATULATIONS!!!!\n" << name1 << " wins the game" << endl;
								else
									cout << "\nSORRY!!!!\nBetter luck next time" << endl;
							}
							cout << "\n\nEnter [1]: Continue" << setw(35) << "[2]: Exit" << endl;
							cin >> inp;
							if (inp == 2)
								return 0;
							system("CLS");
							break;

						case '2':
							cout << "Enter player 1 name: ";
							getline(cin >> ws, ::name1);
							while (true) {
								cout << "Enter player 2 name: ";
								getline(cin >> ws, ::name2);
								if (::name1 != ::name2)
									break;
							}
							while (gameover()) {
								twoply();
								system("CLS");
								table();
							}
							if (draw == true)
								cout << "Match draw" << endl;
							else {
								if (changer == 'O')
									cout << "CONGRATULATIONS!!!!\n" << setw(6) << name1 << " wins the game" << endl;
								else
									cout << "CONGRATULATIONS!!!!\n" << setw(6) << name2 << " wins the game" << endl;
							}
							cout << "\n\nEnter [1]: Continue" << setw(35) << "[2]: Exit" << endl;
							cin >> inp;
							if (inp == 2)
								return 0;
							system("CLS");
							break;
						case 'H':
						case 'h':

							break;
						case 'E':
						case 'e':
							cout << "\n\n\t\t\t\tThank You for using TIC - TAC - TOE !!!!!" << endl;
							return 0;
							break;
						case 'B':
						case 'b':
							system("CLS");
							a = 400; // for break;
							break;
						}
					}
				}
			}
			else if (a == 3) {
				cout << "\n\n\t\t\t\tThank You for using TIC - TAC - TOE !!!!!" << endl;
				return 0;
			}
			else
				cout << "\n\t\t\t\tYou Entered Wrong number!!!!!!\n\n" << endl;
		}
	}
	return 0;
}

void twoply() {
	if (changer == 'X')
		cout << name1 << "'s turn [X]: ";
	else
		cout << name2 << "'s turn [O]: ";
	cin >> choice;
	if (choice > 0 && choice <= 9) {
		if (menu[choice - 1] != 'X' && menu[choice - 1] != 'O') {
			if (changer == 'X') {
				menu[choice - 1] = 'X';
				changer = 'O';
			}
			else {
				menu[choice - 1] = 'O';
				changer = 'X';
			}
		}
		else {
			cout << "The spot is already taken" << endl;
			twoply();
		}
	}
	else {
		cout << "The number you entered is invalid" << endl;
		twoply();
	}

}
void singleplayer() {
	if (changer == 'X') {
		cout << name1 << "'s turn [X]: ";
		cin >> choice;
	}
	else
		cout << "Computer's turn [O]: ";

	if (choice > 0 && choice <= 9) {
		if (menu[choice - 1] != 'X' && menu[choice - 1] != 'O') {
			switch (counter) {
			case 1:
				if (choice == 5) {
					menu[4] = 'X';
					menu[0] = 'O';
					counter = 21;
				}
				else {
					menu[choice - 1] = 'X';
					menu[4] = 'O';
					counter = 22;
				}
				fc = choice;
				break;
			case 21:
				if (choice == 9) {
					menu[8] = 'X';
					menu[2] = 'O';
					counter = 31;
				}
				else {
					menu[choice - 1] = 'X';
					menu[9 - choice] = 'O';
					counter = 32;
				}
				lc = choice;
				break;
			case 31:
				if (choice == 2) {
					menu[choice - 1] = 'X';
					menu[9 - choice] = 'O';
					counter = 41;
				}
				else {
					menu[choice - 1] = 'X';
					menu[1] = 'O';
				}
				lc = choice;
				break;
			case 32:
				if (choice == 9) {
					menu[8] = 'X';
					switch (lc) {
					case 2:
					case 3:
						menu[3] = 'O';
						break;
					case 4:
					case 8:
						menu[2] = 'O';
						break;
					case 6:
						menu[6] = 'O';
						break;
					case 7:
						menu[1] = 'O';
						break;
					}
					counter = 41;
				}
				else {
					menu[choice - 1] = 'X';
					menu[9 - choice] = 'O';
					counter = 42;
				}
				lc = choice;
				break;
			case 41:
				menu[choice - 1] = 'X';

				if (menu[9 - choice] == 'O') {
					for (int i = 0; i < 9; i++) {
						if (menu[i] != 'X' && menu[i] != 'O') {
							menu[i] = 'O';
							break;
						}
					}
				}
				else
					menu[9 - choice] = 'O';
				counter = 51;
				lc = choice;
				break;
			case 42:
				if (choice == 9) {
					menu[8] = 'X';
					for (int i = 0; i < 9; i++) {
						if (menu[i] != 'X' && menu[i] != 'O') {
							menu[i] = 'O';
							break;
						}
					}
					counter = 51;
				}
				else {
					menu[choice - 1] = 'X';
					menu[9 - choice] = 'O';
					counter = 51;
				}
				lc = choice;
				break;
				counter = 51;
				lc = choice;
				break;
			case 51:
				menu[choice - 1] = 'X';
				break;
			case 22:
				menu[choice - 1] = 'X';
				if (fc == 2 && choice == 7 || fc == 2 && choice == 9)
					a == choice - 4;
				else if (fc == 4 && choice == 3 || fc == 4 && choice == 9)
					a == choice - 2;
				else if (fc == 6 && choice == 1 || fc == 6 && choice == 7)
					a == choice;
				else if (fc == 8 && choice == 1 || fc == 6 && choice == 3)
					a == choice + 2;
				else
					a = winning();
				menu[a] = 'O';
				lc = choice;
				counter = 34;
				break;
			case 34:
				menu[choice - 1] = 'X';
				a = winning();
				menu[a] = 'O';
				lc = choice;
				counter = 44;
				break;
			case 44:


				menu[choice - 1] = 'X';
				a = winning();
				menu[a] = 'O';
				lc = choice;
				counter = 51;
				break;
			}
		}
		else {
			cout << "The spot is already taken" << endl;
			singleplayer();
		}
	}
	else {
		cout << "The number you entered is invalid" << endl;
		singleplayer();
	}

}


bool gameover() {
	for (int i = 0; i <= 2; i++) {
		if (menu[i] == menu[i + 3] && menu[i] == menu[i + 6])
			return false;
	}
	for (int i = 0; i <= 6; i = i + 3) {
		if (menu[i] == menu[i + 1] && menu[i] == menu[i + 2])
			return false;
	}
	if (menu[0] == menu[4] && menu[0] == menu[8] || menu[2] == menu[4] && menu[2] == menu[6])
		return false;

	for (int i = 0; i <= 8; i++) {
		if (menu[i] != 'X' && menu[i] != 'O')
			return true;

	}
	draw = true;
	return false;
}

int notcenter() {
	int  x = -1;
	for (int i = 0; i <= 2; i = i + 2) {
		if (menu[i] == menu[i + 3])
			x = i + 6;
		else if (menu[i] == menu[i + 6])
			x = i + 3;
		else if (menu[i + 3] == menu[i + 6])
			x = i;
	}
	if (x != -1)
		if (menu[x] == 'X' || menu[x] == 'O')
			x = -1;
	if (x == -1) {
		for (int i = 0; i <= 6; i = i + 6) {
			if (menu[i] == menu[i + 1])
				x = i + 2;
			else if (menu[i] == menu[i + 2])
				x = i + 1;
			else if (menu[i + 1] == menu[i + 2])
				x = i;
		}
	}
	if (x != -1)
		if (menu[x] == 'X' || menu[x] == 'O')
			x = -1;
	if (x == -1) {
		for (int k = 2; k > -5; k = k - 2) {
			if (menu[choice + k] != 'O' && menu[choice + k] != 'X') {
				if (choice + k <= 9 && choice + k >= 0)
					return choice + k;
				else
					continue;
			}
		}
	}
	if (x == -1) {
		for (int i = 0; i < 9; i++) {
			if (menu[i] != 'X' && menu[i] != 'O') {
				if (i <= 9 && i >= 0)
					return i;
				else
					continue;
			}
		}

	}
	if (x <= 9 && x >= 0) {
		if (menu[x] != 'O' && menu[x] != 'X') {
			return x;
		}
	}
}

int winning() {
	for (int i = 0; i < 9; i++) {
		if (i == 4)
			continue;
		if (menu[8 - i] == 'O' && menu[i] != 'X')
			return i;
	}
	return notcenter();
}

void Admin() {
	fstream admin;
	cout << "\nEnter your username: ";
	getline(cin >> ws, adm);
	cout << "Enter your password: ";
	getline(cin >> ws, adm1);
	admin.open(adm + ".txt", ios::in);
	if (admin) {
		getline(admin, input, '\n');
		admin.close();
		while (true) {
			if (input == adm1) {
				system("CLS");
				cout << "\t\t\t\tWelcome to the Admin Page!!!!!";
				cout << "\n\n[1]:- Add a New Admin" << setw(65) << "[2]:- Edit Highscore" << setw(65) << "[3]:- Back" << endl;
				cout << "Enter: ";
				cin >> a;
				if (a == 1) {
					while (true) {
						cout << "\nEnter New Admin Name: ";
						getline(cin >> ws, adm);
						admin.open(adm + ".txt", ios::in);
						if (admin) {
							cout << "\n\t\t\tThis username already exist!!!!" << endl;
							cout << "[1]: Retry" << setw(35) << "[2]: Back" << endl;
							cout << "Enter: ";
							cin >> a;
							admin.close();
							if (a == 2) {
								a = 3;//because leave from while loop below
								break;
							}
						}
						else {
							admin.close();
							admin.open(adm + ".txt", ios::out);
							break;
						}
					}
					while (true) {
						if (a == 3)
							break; // because back to the menu
						cout << "Enter New Admin Password: ";
						getline(cin >> ws, adm);
						cout << "Confirm Password: ";
						getline(cin >> ws, adm1);
						if (adm == adm1) {
							admin << adm;
							admin.close();
							cout << "\n\n\t\t\t\t\tNew Admin was Added!!!!!!\n\n";
							break;
						}
						else {
							cout << "\nPassword Not matched!!!!!\n" << endl;
							cout << "[1]: Retry" << setw(35) << "[2]: Back" << endl;
							cout << "Enter: ";
							cin >> a;
							if (a == 2)
								break;
						}
					}
				}
				else if (a == 2) {
					cout << "Welcome to Highscore" << endl;
				}
				else if (a == 3) {
					system("CLS");
					break;
				}
			}
			else {
				cout << "\t\t\tYou Entered Wrong Username or Password!!!!!!\n" << endl;
				break;
			}
		}
	}
	else {
		cout << "\t\t\tYou Entered Wrong Username or Password!!!!!!!!\n" << endl;
	}
}
