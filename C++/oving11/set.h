#pragma once
#include <set>
#include <iostream>
#include <string>

void testSet(std::set<int> &testList);

template<class T1, class T2>

void shuffle(T2 table[], T1 size) {
	T2 temp;
	for (int i = 0; i < size; i++) {
		temp = table[i];
		T1 index = rand() % size;
		std::cout << index << endl;
		table[i] = table[index];
		table[index] = temp;
	}
}

template <class T3>
int maximum(T3 a, T3 b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

