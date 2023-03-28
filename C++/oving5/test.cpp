#include <iostream>
#include <string>

#include "CardDeck.h"
#include "cardClass.h"
#include "test.h"
#include "card.h"
#include "BlackJack.h"
using namespace std;

void testOppg1Og2() {
	cout << "***** OPPPGAVE 1 OG 2 *****" << endl;
	cout << suitToString(HEARTS) << endl;
	cout << rankToString(KING) << endl;

	CardStruct card;
	card.s = DIAMONDS;
	card.r = JACK;

	cout << toString(card) << endl;

	cout << toStringShort(card) << endl;


	// erasing from vector
	vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 0; i < 10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase(myvector.begin() + 5);

		// erase the first 3 elements:
		//myvector.erase(myvector.begin(), myvector.begin() + 3);

		//std::cout << "myvector contains:";
		//for (unsigned i = 0; i<myvector.size(); ++i)
		//	std::cout << ' ' << myvector[i];
		//std::cout << '\n';

		for (int i = 0; i < 6; i++) {
			cout << myvector[i] << " ";
		}


}

void testOppg3() {
	cout << "\n***** TEST AV CardClass *****" << endl;
	CardStruct card;
	card.s = HEARTS;
	card.r = NINE;

	Card testCard;
	testCard.initialize(CLUBS, FIVE);
	cout << "testCard.getSuit(): " << testCard.getSuit() << endl;
	cout << "testCard.getRank(): "<<testCard.getRank() << endl;
	cout << "testCard.toString(): "<<testCard.toString() << endl;


	cout << "\n***** TEST AV CardDeck *****" << endl;
	CardDeck testCardDeck;
	//testCardDeck.print(); //LAAAANG
	//testCardDeck.swap(2,3); //TEST. Husk å legge funksjonen i public
	//testCardDeck.printShort();
	//testCardDeck.shuffle();
	//testCardDeck.print(); //LAAAANG
	

	cout << "\n***** TEST AV drawCard() *****" << endl;
	Card testDraw1 = testCardDeck.drawCard();
	cout <<"testDraw.toString(): " <<testDraw1.toString() << endl;
	Card testDraw2 = testCardDeck.drawCard();
	cout << "testDraw.toString(): " << testDraw2.toString() << endl;
	Card testDraw3 = testCardDeck.drawCard();
	cout << "testDraw.toString(): " << testDraw3.toString() << endl;
	
}

void testBlackJack() {
	cout << "\n***** TEST AV BlackJack() *****" << endl;
	Card testCard;
	testCard.initialize(CLUBS, SEVEN);
	
	BlackJack testAceCard;
	cout << "testAceCard: " << testAceCard.isAce(testCard) << endl;

	BlackJack rankOfCard;
	cout << "rankOfCard: " << rankOfCard.getCardValue(testCard) << endl;

	BlackJack rankForPlayer;
	cout << "rankForPlayer: "<<rankForPlayer.getPlayerCardValue(testCard) << endl;

	BlackJack rankForDealer;
	cout << "rankForDealer: "<<rankForDealer.getDealerCardValue(testCard, 18) << endl;

	BlackJack go;
	//cout << go.askPlayerDrawCard() << endl;

	BlackJack initCard;
	initCard.drawInitialCard();

	BlackJack game;
	int newGame = 1;
	while (newGame == 1) {
		game.playGame();
		cout << "\nVil du spille på ny? Du kan alltids satse sølvtøyet til svigermor. Skriv 1 hvis du tar sjansen. Skriv 2 om du bailer." << endl;
		cin>> newGame;
	}
	
}