#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
#include"oppg4.h"
#include "CourseCatalog.h"

//Slette alle chars som ikke er en del av a-z, A-Z, 0-9, mellomrom,


//Antall ganger hvert ord forekommer
	// Lager en map. For hvert ord man leser, sjekker man om dette ordet er en medlem i map.
	// 1) Ikke medlem -> legget det til + gi tilhørende verdi 1
	// 2) medlem -> oppdatere til verdien til ordet

//Hvilket ord som er lengst
	// 

string eraseNotLetters(string wordIn) {
	string wordOut = "";
	for (int i = 0; i < wordIn.length(); i++) {
		if (isalpha(wordIn[i])) {
			wordOut += wordIn[i];
		}
	}
	return wordOut;
}
bool searchForElement(string element, map<string, int>map) {
	if (map.find(element) == map.end()) {
		return false;
	}
	else {
		return true;
	}
}
bool searchForWord(vector<string> longestWord, string word) {
	for (int i = 0; i < longestWord.size(); i++) {
		if (word == longestWord[i]) {
			return true;
		}
	}
	return false;
}


void textStatistics(string file) {
	ifstream document; //Åpner dokument med feilsøk
	document.open(file);
	if (document.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	//Definerer ulike variabler
	string line;
	map<string, int> mapOfWords;
	CourseCatalog catalogOfWords = CourseCatalog(mapOfWords);
	int wordCounter = 0;
	int lineCounter = 0;
	vector<string> longestWordString;
	int longestWordInt = 0;

	//leser dokument og lager statistikk
	while (!document.eof()) {
		getline(document, line);
		//cout << line << endl;
		stringstream ss(line); // Henter ut hvert enkelt ord
		do
		{
			string word;
			ss >> word;
			word = eraseNotLetters(word); //Sletter spesialtegn med funksjon definert tidligere
			if (word != "") { //If-setningen for å unngå å telle mellomrom
				wordCounter += 1;
			}
			cout << word << std::endl;

			//Legger til antall ganger et ord er i teksten
			if (searchForElement(word, mapOfWords)) {
				mapOfWords[word] += 1;
			}
			else {
				mapOfWords[word] = 1;
			}


			//Sjekker lengste ord
			if (word.length() >= longestWordInt && !searchForWord) {
				if (word.length() > longestWordInt) {
					// Sletter alle elementene i vektoren i tilfelle det finnes flere som er like lange.
					longestWordString.clear();
					longestWordString.push_back(word);
					longestWordInt = word.length();
				}
				else {
					longestWordString.push_back(word);
				}

			}

		} while (ss);
		
	}
	lineCounter = mapOfWords[""];
	mapOfWords.erase("");
	cout << "wordCounter: " << wordCounter << endl;
	cout << "lineCounter: " << lineCounter << endl;
	
	if (longestWordString.size() == 1) {
		cout << "Det lengste ordet er " << longestWordString[0] << "og har "<<longestWordInt<<"bokstaver"<< endl;
	}
	else {
		cout << "De lengste ordene er ";
			for (int i = 0; i< longestWordString.size(); i++) {
				cout << longestWordString[i]<<", ";
			}
			cout << "De har " << longestWordInt << " bokstaver" << endl;
	}
	
	for (auto it = mapOfWords.begin(); it != mapOfWords.end(); it++) {
		cout<<it->first << ": " << it->second << endl;
	}

	document.close();
}

