#include<iostream>
using namespace std;
#include "oppg1.h"

void fillInFibonacciNumbers(int result[], int length) {
	if (length == 0) {
		result[0] = 0;
	}
	else {
		result[0] = 0;
		result[1] = 1;
		for (int i = 2; i < length; i++) {
			result[i] = result[i - 2] + result[i - 1];
		}
	}
}

void printArray(int result[], int length) {
	cout << "De "<<length<< " første fibonaccitallene er: " << endl;
	for (int i = 0; i < length; i++) {
		cout << result[i] << endl;
	}
}

void createFibonacci() {
	cout << "Hvor mange tall vil du ha i fibonaccirekka?" << endl;
	int length;
	cin >> length;
	int *result = new int[length];
	fillInFibonacciNumbers(result, length);
	printArray(result, length);
	delete [] result;
}