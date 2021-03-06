// chp5mine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int intMaxGrid = 10;
	char aryGrid[intMaxGrid][intMaxGrid];
	int intXLocation = 0;
	int intYLocation = 0;
	int intXGuess = 0;
	int intYGuess = 0;
	char chrHitMiss = ' ';

	for (int intYPrint = 0; intYPrint < intMaxGrid; intYPrint++) {
		for (int intXPrint = 0; intXPrint < intMaxGrid; intXPrint++) {
			aryGrid[intXPrint][intYPrint] = '.';
		}
	}

	srand(time(0));
	intXLocation = (rand() % intMaxGrid) + 1;
	intYLocation = (rand() % intMaxGrid) + 1;
	cout << intXLocation << ',' << intYLocation << endl;
	do {
		do {
			cout << "Enter an x location guess: ";
			cin >> intXGuess;
		} while (intXGuess < 0 || intXGuess > intMaxGrid + 1);
		do {
			cout << "Enter an y location guess: ";
			cin >> intYGuess;
		} while (intYGuess < 0 || intYGuess > intMaxGrid + 1);

		if ((intXLocation == intXGuess) && (intYLocation == intYGuess)) {
			chrHitMiss = 'H';
		}
		else {
			chrHitMiss = 'M';
		}
		aryGrid[intXGuess - 1][intYGuess - 1] = chrHitMiss;

		for (int intYPrint = 0; intYPrint < intMaxGrid; intYPrint++) {
			for (int intXPrint = 0; intXPrint < intMaxGrid; intXPrint++) {
				cout << aryGrid[intXPrint][intYPrint];
			}
			cout << endl;
		}
	} while ((intXLocation != intXGuess) || (intYLocation != intYGuess));

	return 0;
}

