#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CardClass.h"

using namespace std;


class CardDeck {
private:
	vector<Card> deck;
	int currentCardIndex;
	void swap(int i, int j);
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
};