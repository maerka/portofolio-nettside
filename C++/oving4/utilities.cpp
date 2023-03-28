#include <iostream>
using namespace std;
#include "utilities.h"


// OPPGAVE 1B)
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

//OPPGAVE 1D)
void incrementByValueNumTimes2(int *startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

//OPPG 1E)
//Bruker pekere fordi man "returnerer" to tall
void swapNumbers(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

// OPPG 2C)
void printArray(int table[], int size) {
	for (int i = 0; i < size;i++) {
		cout << table[i]<<" ";
	}
	cout << endl;
}

// OPPG 2D)
int randomWithLimits(int lowerLimit, int upperLimit) {

	int ranNum = std::rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
	return ranNum;
}

void randomizeArray(int table[], int size) {
	for (int i = 0; i < size; i++) {
		int randomNum = randomWithLimits(0, 100);
		table[i] = randomNum;
	}
}

// OPPG 3A)
// Hva er greia med bool swapped?????

void sortArray(int table[], int size) {
	//bool swapped = true;
	for (int j = 0; j < size; j++) {
		//swapped = false;
		for (int i = 0; i < size-1; i++) {
			if (table[i + 1] < table[i]) {
				swapNumbers(&table[i], &table[i + 1]);
				//swapped = true;
			}
		}
	}
}
// OPPG 3B)
int medianOfArray(int table[], int size) {
	if (size % 2 == 0) {
		//Deler size på 2 for å finne midten av tabellen. Tar gjennomsnittet 
		//av de 2 elementene i midten. Runder av
		double m1 = table[size / 2 - 1];
		double m2 = table[size / 2];
		return round((m1 + m2) / 2);
	}
	else {
		//elementnummer er en integer og rundes derfor ned.
		return table[size / 2];
	}
}


// OPPG 4C)
void randomizeCString(char table[], int size, char lowerLimit, char upperLimit) {
	for (int i = 0; i < size-1; i++) {
		table[i] = randomWithLimits(lowerLimit, upperLimit);
	}
}
// OPPG 4F)
void readInputToCString(char table[], int size, char lowerLimit, char upperLimit) {
	cout << "Skriv inn " << size-1 << " verdier fom. " << lowerLimit << " tom. " << upperLimit <<"."<< endl;
	int counter = 0;
	//while (counter != size) {
	for (int i = 0; i<size-1; i++){
		char input;
		cout << "Skriv en verdi nr. "<< i+1<<":" << endl;
		cin >> input;
		input = toupper(input);
		if (input >= lowerLimit && input <= upperLimit) {
			table[i] = input;
		}
		else {
			//Hindrer løkka i å telle videre om man ikke angir korrekt verdi.
			i -= 1;
			cout << "Ugyldig verdi. Prøv på ny." << endl;
		}
	}
}
// OPPG 4G)
int countOccurencesOfCharacter(char string[], int size, char value) {
	int counter = 0;
	value = toupper(value); //Godtar små og store bokstaver
	for (int i = 0; i < size; i++) {
		if (string[i] == value) {
			counter += 1;
		}
	}
	return counter;
}


int checkCharactersAndPosition(char code[], char guess[], int SIZE){
	int counter = 0;
	for (int i = 0; i < SIZE-1; i++) {
		if (code[i] == guess[i]) {
			counter += 1;
		}
	}
	return counter;
}

int checkCharacters(char code[], char guess[], int SIZE, int LETTERS) {
	int correctGuess = 0;
	char character = 'A';
	for (int i = 0; i < LETTERS + 1; i++) {
		int occurencesCode = countOccurencesOfCharacter(code, SIZE, character);
		//cout << "I code er antall "<<character <<": "<<occurencesCode << endl;
		int occurencesGuess = countOccurencesOfCharacter(guess, SIZE, character);
		//cout << "I guess er antall " << character << ": " << occurencesGuess << endl;

		if (occurencesCode >= occurencesGuess) {
			correctGuess += occurencesGuess;
		}
		else if(occurencesCode < occurencesGuess){
			correctGuess += occurencesCode;
		}
		character += 1;
	}
	return correctGuess;
}