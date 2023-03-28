#include <iostream>
#include "utilities.h"
using namespace std;

void printArray(int table[], int size) {
	for (int i = 0; i < size; i++) {
		cout << table[i] << " ";
	}
	cout << endl;
}