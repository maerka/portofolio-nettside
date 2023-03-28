#pragma once
#include "CardDeck.h"
#include "cardClass.h"
#include "card.h"

class BlackJack {
private:
	CardDeck deck;
	int playerHand;
	int playerCardsDrawn;
	int dealerHand;
	int dealerCardsDrawn;
public:
	bool isAce(Card cardCheck); //Hvordan få til pekere??
	int getCardValue(Card cardCheck);
	int getPlayerCardValue(Card cardCheck);
	int getDealerCardValue(Card card,int valueOnHand);
	bool askPlayerDrawCard();
	void drawInitialCard();
	void playGame();
};