#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <forward_list>
using namespace std;
#include "vector.h"
#include "set.h"
#include "SimpleSet.h"
#include "Person.h"

void testMe1(int *a, int *b) {
	std::cout << a << std::endl;
	std::cout << *a << std::endl;
	
	int *temp = a;
	a = b;
	b = temp;

	std::cout << a << std::endl;
	std::cout << *a << std::endl;
	std::cout << b << std::endl;
	std::cout << *b << std::endl;
}

void testMe2(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void testMe3(int a, int &b) {
	std::cout << "testMe3" << std::endl;
	std::cout << a << std::endl;
	std::cout << &b << std::endl;
	//int *test;
	//test = a;
	//a = b;
	//b = *test;
}

int main() {
	// ***** OPPGAVE 1 *****
	int var3 = 10;
	int var4 = 20;
	testMe1(&var3, &var4);
	testMe2(&var3, &var4);
	testMe3(var3, var4);

	std::cout << var3 << std::endl;
	std::cout << var4 << std::endl;


	vector<string> stringVector;
	stringVector.push_back("Hans");
	stringVector.push_back("Vigdis");
	stringVector.push_back("Tomas");
	stringVector.push_back("Noora");
	stringVector.push_back("Ompalompa");

	writeVector(stringVector);
	writeVectorReversed(stringVector);
	replaceWords(stringVector, "Tomas", "WillieWonka");
	writeVector(stringVector);


	// ***** OPPGAVE 2 *****
	set<int> numbList;
	for (int i = 0; i < 101; i++) {
		numbList.insert(i);
	}
	testSet(numbList);

	//set<int>::iterator it = numbList.find(47);
	if (numbList.count(46)) {
		cout << "In set" << endl;
	}

	//SimpleSet mySet = SimpleSet();
	SimpleSet<double> mySet;
	for (double i = 0; i < 101; i++) {
		if (mySet.insert(i));
	}

	for (int i = 2; i < 51; i++) {
		for (int k = 0; k < 101; k++) {
			if (k != i && k%i == 0) {
				mySet.remove(k);
			}
		}
	}

	std::cout << mySet << std::endl;
	std::cout << "***** SLUTT OPPGAVE 2D *****" << std::endl;


	// ***** OPPGAVE 3 *****
	double a[] = {1, 2, 3, 4};
	shuffle(a, 4);
	
	string c[] = { "one", "two", "three", "four" };
	shuffle(c, 4);

	for (auto i = 0; i < 4; i++) {
		cout << a[i] << "\t";
	}

	char var1 = 'c';
	char var2 = 'n';
	cout << "maximum: " << maximum(var1, var2) << endl;

	// ***** OPPGAVE 5 *****
	Person p1 = Person("Viggern", "Juliussen");
	Person p2 = Person("TrondViggo", "Torgersen");
	Person p3 = Person("Donald", "Duck");
	Person p4 = Person("Forrest", "Gump");
	forward_list<Person> personList;



	p1.insertOrdered(personList, p1);
	p2.insertOrdered(personList, p2);
	p3.insertOrdered(personList, p3);
	p4.insertOrdered(personList, p4);


	for (forward_list<Person>::iterator it = personList.begin(); it!=personList.end(); it++) {
		cout << *it << endl;
	}


	return 0;
}







