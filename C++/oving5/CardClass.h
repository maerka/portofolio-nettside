#pragma once
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

class Card {
private:
	Suit s;
	Rank r;
	bool invalid;
public:
	void initialize(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	string toString();
	string toStringShort();
	Card();
	Card(Suit s, Rank r);
};