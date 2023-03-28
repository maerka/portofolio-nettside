#include "Dummy.h"
#include <iostream>
using namespace std;


void dummyTest() {
	cout << "***** DEN STORE STYGGE DUMMYTESTEN *****" << endl;
	Dummy a;
	*a.num = 4;
	Dummy b(a);
	Dummy c;
	c = a;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	*b.num = 3;
	*c.num = 5;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	cin.get();
}

Dummy::Dummy(const Dummy &other) :num(nullptr) {
	this->num = new int();
	*num = *other.num;
}

Dummy Dummy::operator = (const Dummy rhs) {
	swap(*num, *rhs.num);
	return *this;
}
// Denne versjonen fungerer også...
//Dummy Dummy::operator = (Dummy rhs) {
//	swap(num, rhs.num);
//	return *this;
//}