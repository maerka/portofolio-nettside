#pragma once

//***** OPPGAVE 1 *****
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimes2(int *startValue, int increment, int numTimes);

void swapNumbers(int *a, int *b);

void printArray(int table[], int size);

int randomWithLimits(int lowerLimit, int upperLimit);

void randomizeArray(int table[], int size);

void sortArray(int original[], int size);

int medianOfArray(int table[], int size);

void randomizeCString(char table[], int size, char lowerLimit, char upperLimit);

void readInputToCString(char table[], int size, char lowerLimit, char upperLimit);

int countOccurencesOfCharacter(char string[], int size, char value);

int checkCharactersAndPosition(char code[], char guess[], int SIZE);

int checkCharacters(char code[], char guess[], int SIZE, int LETTERS);