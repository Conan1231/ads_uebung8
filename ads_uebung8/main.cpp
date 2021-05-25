#include <iostream>
#define N 20

using namespace std;

int counter = 0;
int erg[N];


bool freePlace(int row, int column) {
	counter++;
	for (int i = 0; i < row; i++) {
		if (erg[i] == column)
			return false;
		if (erg[i] + i == column + row)
			return false;
		if(erg[i] - i == column - row)
			return false;
	}
	return true;
}



bool placeQueen(int row) {
	if (row == N)
		return true;
	for (int column = 0; column < N; column++) {
		if (freePlace(row, column)) {
			erg[row] = column;
			if (placeQueen(row + 1))
				return true;
			erg[row] = -1;
		}
	}
	return false;
}

void printErg() {
	for (int i = 0; i < N; i++) {
		cout << i << " " << erg[i] << endl;
	}
	cout << "Funktionsaufrufe: " << counter << endl;
}

void print() {
	for (int row = 0; row < N; row++) {
		for (int column = 0; column < N; column++) {
			if (erg[row] == column)
				cout << " D";
			else
				cout << " °";
		}
		cout << endl;
	}
}

int main() {

	placeQueen(0);
	printErg();
	print();

	// Komplexitaet von O(n^2)
	// Funktionsaufrufe N=5: 15 
	// Funktionsaufrufe N=10: 975
	// Funktionsaufrufe N=20: 3.992.510
	return 0;
}