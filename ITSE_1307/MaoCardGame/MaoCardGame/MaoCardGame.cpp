// MaoCardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum cardsuite {CLUBS, DIAMONDS, HEARTS, SPADES};

int getFaceValue(int intCard) {
	//Function to get the face value of the card
	return 1 + ((intCard - 1) % 13);
}

int getSuiteValue(int intCard) {
	//Function to geth the suite value of the card
	return (intCard - 1) / 13;
}

string getFaceString(int intCard) {
	//Function to get the face as a string of a card
	int intFace = getFaceValue(intCard);
	string strFace = "";
	switch (intFace) {
		case 1:
			strFace = "Ace";
			break;
		case 11:
			strFace = "Jack";
			break;
		case 12:
			strFace = "Queen";
			break;
		case 13:
			strFace = "King";
			break;
		default:
			strFace += std::to_string(intFace);
	}
	return strFace;
}

string getSuiteString(int intCard) {
	//Returns the suite of the card as a string
	string strSuite = "";
	switch (getSuiteValue(intCard)) {
		case CLUBS:
			strSuite = "Clubs";
			break;
		case DIAMONDS:
			strSuite = "Diamonds";
			break;
		case HEARTS:
			strSuite = "Hearts";
			break;
		default:
			strSuite = "Spades";
			break;
	}
	return strSuite;
}

string getCardString(int intCard) {
	//Returns the full card as a string
	return getFaceString(intCard) + " of " + getSuiteString(intCard);
}

int pickACard() {
	//Lets the user pick a random number
	int intCard = 0;
	do {
		cout << "Please enter a card number between 1 and 52: ";
		cin >> intCard;
	} while (intCard < 1 || intCard > 52);
	return intCard;
}

int getRandomCard() {
	//Generates a random card number
	return rand() % 52 + 1;
}

void printIntDeck(int aryDeck[]) {
	int intArraySize = (sizeof(aryDeck) / sizeof(aryDeck[0]));
	cerr << intArraySize << endl;
	for (int intIndex = 0; intIndex < intArraySize; intIndex++) {
		cout << aryDeck[intIndex];
	}
}

void createDeck(int aryDeck[], int intNumberOfDecks = 1) {
	int intDeckIndex = 0;
	for (int intCurrentDeck = 1; intCurrentDeck <= intNumberOfDecks; intCurrentDeck++) {
		for (int intCurrentCard = 1; intCurrentCard <= 52; intCurrentCard++) {
			aryDeck[intDeckIndex] = intCurrentCard;
			//cerr << getCardString(aryDeck[intDeckIndex]) << endl;
			intDeckIndex++;
		}
	}
}

int main()
{
	srand(time(0)); //Setup the randomness at the beginning of the program
	const int INTNUMBEROFDECKS = 4;
	int aryDeck[52 * INTNUMBEROFDECKS];
	createDeck(aryDeck, INTNUMBEROFDECKS);
	//cerr << (sizeof(aryDeck) / sizeof(aryDeck[0])) << endl;
	printIntDeck(aryDeck);

	int intCard = getRandomCard(); //Generates a card
	cout << getCardString(intCard) << endl; //Displays a card

    return 0;
}

