#include <iostream>
#include <string>
#include "card.h"
using namespace std;

string suitToString(Suit suit) {
	string suitString;
	switch (suit) {
	case HEARTS: {
		suitString = "HEARTS";
		break; }
	case DIAMONDS: {
		suitString = "DIAMONDS";
		break; }
	case CLUBS: {
		suitString = "CLUBS";
		break; }
	case SPADES: {
		suitString = "SPADES";
		break; }
	}
	return suitString;
}

string rankToString(Rank rank) {
	string rankString;
	switch (rank){
	case TWO: {
		rankString = "TWO";
		break; }
	case THREE: {
		rankString = "THREE";
		break; }
	case FOUR: {
		rankString = "FOUR";
		break; }
	case FIVE: {
		rankString = "FIVE";
		break; }
	case SIX: {
		rankString = "SIX";
		break; }
	case SEVEN: {
		rankString = "SEVEN";
		break; }
	case EIGHT: {
		rankString = "EIGHT";
		break; }
	case NINE: {
		rankString = "NINE";
		break; }
	case TEN: {
		rankString = "TEN";
		break; }
	case JACK: {
		rankString = "JACK";
		break; }
	case QUEEN: {
		rankString = "QUEEN";
		break; }
	case KING: {
		rankString = "KING";
		break; }
	case ACE: {
		rankString = "ACE";
		break; }
	}
	return rankString;
}

string toString(CardStruct card) {
	string returnString = rankToString(card.r) + " of " + suitToString(card.s);
	return returnString;
}

string toStringShort(CardStruct card) {
	string suit = suitToString(card.s).substr(0,1); //Henter første bokstav til sorten
	string rank = to_string(card.r+2); //Henter ut tallet
	return suit+rank;
}

int randomWithLimits(int lowerLimit, int upperLimit) {

	int ranNum = std::rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
	//std::cout << "ranNumTest % upperLimit + lowerLimit: " << ranNum << std::endl;
	return ranNum;
}