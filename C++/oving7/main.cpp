#include<iostream>
using namespace std;
#include "oppg1.h"
#include "Matrix.h"
#include "Dummy.h"

void main() {
	//setlocale(LC_ALL, "Norwegian");
	//createFibonacci();

	Matrix matrise1 = Matrix(3,6);
	double element1 = matrise1.get(2, 2);
	matrise1.set(2, 4, 5);
	cout << element1 << endl;

	Matrix matrise2 = Matrix(6);
	double element2 = matrise2.get(3, 3);
	double element3 = matrise2.get(3, 4);
	matrise2.set(0, 1, 7);
	cout << element2 << endl;
	cout << element3 << endl;

	Matrix matrise3 = Matrix();

	cout << "matrise3:" << endl;
	cout << matrise3 << endl;
	cout << "matrise1:" << endl;
	cout << matrise1 << endl;
	cout << "matrise2:" << endl;
	cout << matrise2 << endl;

	Matrix matrise4 = matrise2;
	cout << "matrise4:" << endl;
	cout << matrise4 << endl;

	matrise4 += matrise2;
	cout << "matrise4:" << endl;
	cout << matrise4 << endl;

	Matrix matrise5 = Matrix(6, 5);
	cout << "matrise5:" << endl;
	cout << matrise5 << endl;
	//matrise4 += matrise5; //Gir kjøretidsfeil
	
	Matrix matrise6 = matrise2 + matrise4;
	cout << "matrise6:" << endl;
	cout << matrise4 << endl;
	//dummyTest();
}