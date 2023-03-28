#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "vector.h"

void writeVector(vector<string>names) {
	cout << "\nI rett rekkefølge:" << endl;
	for (auto it = names.begin(); it != names.end(); ++it) {
		cout << *it << endl;
	}
}

void writeVectorReversed(vector<string>names) {
	cout << "\nReversert:" << endl;
	for (auto it = names.rbegin(); it != names.rend(); ++it) {
		cout << *it << endl;
	}
}


void replaceWords(vector<string> &words, string old, string replace) {
	for (auto it = words.begin(); it !=words.end(); ++it) {
		if (*it == old) {
			it = words.erase(it);
			it = words.insert(it, replace);			
		}
	}
}