#include<iostream>
#include <vector>
using namespace std;
#include "CardDeck.h"
#include "cardClass.h"
#include "card.h"
#include "BlackJack.h"

bool BlackJack::isAce(Card cardCheck) {	
	Rank rankCard = cardCheck.getRank();
	if (rankCard == ACE){
		return true;
	}
	else {
		return false;
	}
}

int BlackJack::getCardValue(Card cardCheck) {
	BlackJack testForAce;
	Rank rankCard = cardCheck.getRank();
	if (testForAce.isAce(cardCheck)) {
		return -1;
	}
	else if (rankCard == JACK || rankCard == QUEEN || rankCard == KING) {
		return 10;
	}
	else {
		return rankCard + 2;
	}
}

int BlackJack::getPlayerCardValue(Card cardCheck) {

	BlackJack valueOfCard;
	int value = valueOfCard.getCardValue(cardCheck);

	if (value == -1){
		while (value != 1 && value != 11) {
			cout << "Du trakk ett ess. Ønsker du at det skal ha verdien 1 eller 11?" << endl;
			cin >> value;
		}	
	}
	return value;
}

int BlackJack::getDealerCardValue(Card card, int valueOnHand) {
	bool resultAceTest = BlackJack::isAce(card);
	int value = BlackJack::getCardValue(card);

	if (resultAceTest) {
		if (valueOnHand>10){
			value = 1;
		}
		else {
			value = 11;
		}
	}
	return value;
}

bool BlackJack::askPlayerDrawCard() {
	cout << "Vil du trekke et nytt kort? Skriv 1 for ja eller 2 for nei." << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		return true;
	}
	else {
		return false;
	}
}

void BlackJack::drawInitialCard() {
	//cout << "\nINNI drawInitialCard" << endl; //TEST
	//deck.shuffle();	//							TeEST

	
	Card card1 = deck.drawCard();
	cout <<"Dealer sitt første kort var: "<<card1.toString() << endl;	
	Card card2 = deck.drawCard();
	Card card3 = deck.drawCard();
	cout << "Ditt første kort var: " << card3.toString() << endl;
	Card card4 = deck.drawCard();
	cout << "Ditt andre kort var: " << card4.toString() << endl;

	//cout << "card2: " << card2.toString() << endl; //TEST
	//cout << "card3: " << card3.toString() << endl; //TEST
	//cout << "card4: " << card4.toString() << endl; //TEST

	dealerHand = BlackJack::getDealerCardValue(card1,dealerHand);
	dealerHand += BlackJack::getDealerCardValue(card2,dealerHand);
	dealerCardsDrawn = 2;
	//cout << "dealherHand: " << dealerHand <<"dealerCardsDrawn: "<< dealerCardsDrawn<< endl;  //TEST

	playerHand = BlackJack::getPlayerCardValue(card3);
	playerHand += BlackJack::getPlayerCardValue(card4);
	playerCardsDrawn = 2;
	//cout << "playerHand: " << playerHand << "playerCardsDrawn: " <<playerCardsDrawn << endl; //TEST
}

void BlackJack::playGame() {
	cout << "\n***** BLACKJACK *****" << endl;
	//Innledende til spillet. Kort deles ut.
	deck.shuffle();
	//deck.print();
	drawInitialCard();
	//cout << "Spillers starthånd: " << playerHand << endl;
	//cout << "Dealers starthånd: " << dealerHand << endl;

	bool playerLost = false;
	bool dealerLost = false;
	
	//Løkke som spør om man vil trekke flere kort.
	bool dealNewCard = true;
	while (askPlayerDrawCard()) {
		//Kort deles til spiller
		Card newCardPlayer = deck.drawCard();
		playerHand += BlackJack::getPlayerCardValue(newCardPlayer);
		playerCardsDrawn++;
		cout << "Du trakk en " << newCardPlayer.toString() << endl;
		if (playerHand > 21) {
			playerLost = true;
			break;
		}
		//Kort  deles til dealer
		if (dealerHand < 17) {
			Card newCardDealer = deck.drawCard();
			dealerHand += BlackJack::getDealerCardValue(newCardDealer, dealerHand);
			dealerCardsDrawn++;
			if (dealerHand > 21) {
				dealerLost = true;
				break;
			}
		}
	}
		//Dealer trekker nytt kort hvis hånda er under 17 etter at spiller har sagt pass.
		if (dealerHand < 17 && dealerLost == false &&playerLost==false) {
			Card newCardDealer = deck.drawCard();
			dealerHand += BlackJack::getDealerCardValue(newCardDealer, dealerHand);
			dealerCardsDrawn++;
			if (dealerHand > 21) {
				dealerLost = true;
			}
		}
		//Avgjør om seier eller tap
		//Ingen har oversteget 21 -> både dealerLost og playlerLost = false
		if (dealerLost == false && playerLost == false) {
			//Spiller har blackjack uten at dealer har det
			if (playerHand == 21 && playerCardsDrawn == 2 && dealerHand == 21 && dealerCardsDrawn > 2) {
				dealerLost = true;
			}
			//Spiller har høyere poengsum enn dealer
			else if (playerHand > dealerHand) {
				dealerLost = true;
			}
			else {
				playerLost = true;
			}
		}

		//Skrive gratulasjonsmelding
		cout << "\nDealer sin avsluttende hånd: " << dealerHand << endl;
		cout << "Din avsluttende hånd: " << playerHand << endl;
		if (dealerLost == true) {
			cout<< "\nGratulerer!Du vant!Whiskeyen settes på huset." << endl;
		}
		else {

			cout << "\nDet var da synd. Du tapte. Oppvasken står klar på kjøkkenet." << endl;
		}

}