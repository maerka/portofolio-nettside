#include "set.h"
#include <set>
#include <iostream>
using namespace std;
int x = 0;



void testSet(set<int> &testList) {
	for (int i = 2; i < 51; i++) {
		for (auto it = testList.begin(); it != testList.end();) {
			//cout << *it << endl;
			if (*it != i && *it % i == 0) {
				it = testList.erase(it);
			}
			else {
				++it;
			}
		}
	}


	for (auto it = testList.begin(); it != testList.end(); ++it) {
		cout << *it << "\t";
	}
}

//void shuffle(T1& table, T2& size) {
//	T2 temp;
//
//	for (int i = 0; i < size; i++) {
//		temp = table[i];
//		T2 index = random() % size;
//		cout << "index: " << index << endl;
//		table[i] = table[index];
//		table[index] = temp;
//	}
//}


