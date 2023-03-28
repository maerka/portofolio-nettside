#include <iostream>
#include <ctime>
using namespace std;
#include "utilities.h"
#include "tests.h"
#include "playMastermind.h"


// ***** OPPG 1 *****
// oppg A)
/* V0: 5
increment: 2
iterations: 10
result:25*/

void main() {
	std::srand(time(nullptr));
	setlocale(LC_ALL, "Norwegian");

	// ***** OPPGAVE 1 *****
	bool finished = false;
	char choice = ' ';
	while (!finished) {
		cout << "***** HOVEDMENY ØVING 4 *****"<<
			"\nVelg oppgave: Skriv 1 for oppg 1, 2 for oppg 2. osv. q for å avslutte."<< 
			"\n...Men om du vil ha noe å bryne deg på, anbefales du å skrive 5. \n"<<
			"Da får du spille det legendariske spillet MASTERMIND." << endl;
			cin >> choice;
		switch (choice) {
		case '1':
			cout << "Oppgave 1C)" << endl;
			testCallByValue();
			cout << "Oppgave 1D)" << endl;
			testCallByPointer();
			cout << "Oppgave 1E)" << endl;
			testSwapNumbers();
			break;
		case '2':
			testTablesSorting();
			break;
		case '4':
			testCStrings();
			break;
		case '5':
			playMastermind();
			break;
		case 'q':
			finished = true;
			break;
		default:
			cout << "***ugyldig valg***\n" << endl;
		}
	}
}

