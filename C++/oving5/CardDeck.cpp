#include <iostream>
#include <string>
#include <ctime>

#include "card.h"
#include "CardDeck.h"
using namespace std;

CardDeck::CardDeck(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++){
			Card cardElement(static_cast<Suit> (i), static_cast<Rank> (j));
			deck.push_back(cardElement);
			//cout << cardElement.toString() << endl; //TEST
		}
	}
	currentCardIndex = 0;
}

void CardDeck::swap(int i, int j) {
	Card temp = deck[i];
	deck[i] = deck[j];
	deck[j] = temp;
}

void CardDeck::print() {
	cout << "\nLang versjon" << endl;
	for (int i= 0; i < 52; i++) {
		Card cardElement = deck[i];
		cout << cardElement.toString() << endl;
	}
}

void CardDeck::printShort() {
	cout << "\nKort versjon" << endl;
	for (int i = 0; i < 52; i++) {
		Card cardElement = deck[i];
		cout << cardElement.toStringShort() << endl;
	}
}

void CardDeck::shuffle() {
	vector<Card> temporary;
	int numElements = 51;
	for (int i = 0; i <52; i++) {
		int ranNum = randomWithLimits(0, numElements); // Lager et tilfeldig nummer fra 0-51. Dette velger hvilket element vi skal jobbe med.
		temporary.push_back(deck[ranNum]); //Legger dette deck-elementet inn i temporary.
		deck.erase(deck.begin() + ranNum); //Sletter dette elementet (kortet) fra deck-vektor. -1 for at den skal telle fra 0.
		numElements--; //Har nå ett mindre element igjen i deck-vector. 
	}
	for (int j = 0; j < 52; j++) {
		deck.push_back(temporary[j]);
	}


	 //TEST I FORM AV UTSKRIFT
	//cout << "Løkke start" << endl;
	for (int k = 0; k < 52; k++) {
		Card cardElementTemp = temporary[k];
		Card cardElementDeck = deck[k];
		//cout << "temp:"<<cardElementTemp.toString() << endl;
		//cout << "deck:" << cardElementDeck.toString() << endl;
	}
	//cout << "Løkke slutt\n" << endl;
}

Card CardDeck::drawCard() {
	
	Card draw = deck[currentCardIndex];
	currentCardIndex +=1;
	return draw;
}