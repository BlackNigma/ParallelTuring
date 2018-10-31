#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;
using namespace std::chrono;

struct TURING_MACHINE {
	string tape, currentState[100], nextState[100];
	string head = " ";
	string newState = "0";
	int index, lineCount = 0;
	char moveTape[100], currentSymbol[100], newSymbol[100];
} Turing[4];

int main() {
	ifstream myFile;
	for (int x = 0; x < 4; x++) {
		myFile.open(to_string(x + 1) + ".txt");
		myFile >> Turing[x].index;
		myFile >> Turing[x].tape;
		while (!myFile.eof()) {
			myFile >> Turing[x].currentState[Turing[x].lineCount]
				>> Turing[x].currentSymbol[Turing[x].lineCount]
				>> Turing[x].newSymbol[Turing[x].lineCount]
				>> Turing[x].moveTape[Turing[x].lineCount]
				>> Turing[x].nextState[Turing[x].lineCount];
			Turing[x].lineCount++;
		}
		myFile.close();
		Turing[x].lineCount--;

		int n = Turing[x].tape.length();
		for (int j = 0; j < n - 1; j++) {
			Turing[x].head.append(" ");
		}
	}

	int x = 0;

	while (x != 5) {
		for (int x = 0; x < 4; x++) {
			while (Turing[x].newState != "X" || Turing[x].newState != "-1") {
				for (int i = 0; i < Turing[x].lineCount; i++) {
					if (Turing[x].newState == Turing[x].currentState[i]) {
						if (Turing[x].currentSymbol[i] == Turing[x].tape[Turing[x].index]) {
							Turing[x].tape[Turing[x].index] = Turing[x].newSymbol[i];
							Turing[x].newState = Turing[x].nextState[i];
							if (Turing[x].newState == "X") {
								break;
							}
							if (Turing[x].moveTape[i] == 'R') {
								Turing[x].head[Turing[x].index] = ' ';
								Turing[x].index++;
								Turing[x].head[Turing[x].index] = '^';
							}
							else {
								Turing[x].head[Turing[x].index] = ' ';
								Turing[x].index--;
								Turing[x].head[Turing[x].index] = '^';
							}
						}
					}
				}
				system("cls");
				for (int i = 0; i < 4; i++) {
					cout << Turing[i].tape << endl;
					cout << Turing[i].head << endl;
				}
				break;
			}
		}
	}
	return 0;
}