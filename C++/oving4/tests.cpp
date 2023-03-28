#include <iostream>
#include <iomanip>
using namespace std;
#include "tests.h"
#include "utilities.h"


// ***** OPPG 1 *****

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << std::endl;
}

void testCallByPointer() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes2(&v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations << endl;
}



void testSwapNumbers() {
	int a = 5;
	int b = 7;
	swapNumbers(&a, &b);
	cout << "a: " << a << "b: " << b << endl;
}


// ***** OPPG 2 *****
void testTablesSorting() {
	cout << "\n***** OPPG 2 *****" << endl;

	int const size = 7;
	int percentages[size] = {};
	cout << "printArray før innlagte verdier:" << endl;
	printArray(percentages,size);
	cout << endl;

	randomizeArray(percentages, size);
	cout << "printArray etter randomizeArray:" << endl;
	printArray(percentages, size);
	cout << endl;

	swapNumbers(&percentages[0], &percentages[1]);
	cout << "printArray etter swapNumbers:" << endl;
	printArray(percentages, size);
	cout << endl;



// ***** OPPG 3 *****
	cout << "\n***** OPPG 3 *****" << endl;

	sortArray(percentages, size);
	cout << "printArray etter sortArray:" << endl;
	printArray(percentages, size);
	cout << endl;

	cout << medianOfArray(percentages, size) << endl;
}



// ***** OPPG 4 *****
void testCStrings() {
	cout << "\n***** OPPG 4 *****" << endl;

	int const size = 40 +1 ; // +1 for å få plass til \0
	char grades[size] = "";
	randomizeCString(grades, size, 'A', 'F');
	cout << grades << endl;

// OPPG F)
	//readInputToCString(grades, size, 'A', 'F');
// OPPG G)
	cout << "countOccurencesOfCharacter: " <<countOccurencesOfCharacter(grades, size, 'A') << endl;
	
//OPPG H og I)
	cout <<"\n***** oppg 4 H,I *****"<<endl;
	int const numberOfGrades = 6;
	int gradeCount[numberOfGrades] = {};
	char grade = 'A';
	int valueOfGrade = 6;
	double totalValue = 0;

	for (int i = 0;  i< numberOfGrades; i++) {
		int occurences = countOccurencesOfCharacter(grades, size, grade);
		//cout << "occurences of "<<grade<<": " << occurences << endl;
		gradeCount[i] = occurences;
		//cout << "gradesCount[" << i << "] = " << gradeCount[i] << endl;
		grade += 1;

		totalValue += valueOfGrade * gradeCount[i];
		valueOfGrade -= 1;
	}
	cout << "test of gradeCount: ";
	printArray(gradeCount, numberOfGrades);
	double average = (totalValue / (size-1));
	cout << "Gjennomsnitt: "<<fixed<<setprecision(1)<<average << endl;
// Hvordan fungerer linja under? Den stod i oppgavetekst. Tror 
	cout << "Gjennomsnitt i bokstaver: "<<static_cast<char> ('A' + round(average) - 1) << endl;
}