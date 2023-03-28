#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Suit{HEARTS, DIAMONDS, CLUBS, SPADES};
enum Rank{TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct CardStruct {
	Suit s;
	Rank r;
};

string suitToString(Suit suit);

string rankToString(Rank rank);

string toString(CardStruct card);

string toStringShort(CardStruct card);

int randomWithLimits(int lowerLimit, int upperLimit);


