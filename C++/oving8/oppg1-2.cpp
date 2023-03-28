#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include"oppg1-2.h"

void writeToFile() {

	ofstream output;
	output.open("file");
	string newWord;
	while (newWord != "quit") {
		cout << "Skriv inn et ord som skrives til fil. Skriv quit for å avslutte." << endl;
		cin >> newWord;
		if (newWord != "quit") {
			output << newWord << endl;
		}
	}
	output.close();
}

void addLineNumbers(string filename) {
	ifstream inputFile;
	inputFile.open(filename);
	ofstream outputFile;
	outputFile.open("fileWithLineNumber");

	if (inputFile.fail() || outputFile.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	int counter = 0;
	string copyOfLine;
	string numberAndLine;

	while (!inputFile.eof()) {
		counter += 1;
		getline(inputFile, copyOfLine);
		numberAndLine = to_string(counter) + " " + copyOfLine + "\n";
		outputFile << numberAndLine;
	}
	inputFile.close();
	outputFile.close();
}

void letterStatistics(string filename) {
	ifstream inputFile;
	inputFile.open(filename);
	if (inputFile.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}
	string line;
	vector <int> letterStatistics(28, 0); //Lager vektor med plass til 27 bokstaver som settes til 0. Siste plass er forbeholdt totalt antall tegn.


	while (!inputFile.eof()) { //Går gjennom hele dokumentet og fører statistikk linje for linje
		getline(inputFile, line);
		cout << line << endl;

		int iterator = 1; //for letterStatistics
		for (char testingLetter = 'a'; testingLetter <= 'z'; testingLetter++) {
			int counter = 0;
			for (int i = 0; i < line.size(); i++) { //Leser første linje og teller #a, #b, #c osv.
				if (line[i] == testingLetter || line[i] == char(tolower(testingLetter))) { //SJekker for både små og store bokstaver
					counter += 1; //antall a,b,c osv.
				}
			}
			letterStatistics[iterator] += counter; //Legger #a, #b, #c inn i statistikken.
			letterStatistics[0] += counter;
			iterator += 1;

		}
	}
	cout << "\nletterStatistics" << endl;
	int it = 1;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		cout << ch << ":" << letterStatistics[it] << " ";
		if (it % 9 == 0) {
			cout << endl;
		}
		it += 1;
	}
	cout << "\nTotalt: " << letterStatistics[0] << endl;
	inputFile.close();
}