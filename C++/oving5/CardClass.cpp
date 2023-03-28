#include <iostream>
#include <string>
#include "card.h"
#include "CardClass.h"
using namespace std;

void Card::initialize(Suit s, Rank r) {
	this->s = s;
	this->r = r;
	invalid = false;
}
Suit Card::getSuit() {
	return s;
}
Rank Card::getRank() {
	return r;
}

string Card::toString() {
	string suit = suitToString(s);
	string rank = rankToString(r);
	if (!invalid) {
		return rank + " of " + suit;
	}
	else {
		return "Invalid card";
	}
}

string Card::toStringShort() {
	string suitShort = suitToString(s).substr(0,1);
	string rankShort = to_string(r + 2);
	if (invalid == false) {
		return suitShort + rankShort;
	}
	else {
		return "Invalid card";
	}
}

Card::Card() {
	invalid = true;
}

Card::Card(Suit s, Rank r) {
	this->s = s;
	this->r = r;
	invalid = false;
}