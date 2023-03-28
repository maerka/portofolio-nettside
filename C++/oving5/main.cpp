#include <iostream>
#include <ctime>
#include "CardDeck.h"
#include "cardClass.h"
#include "test.h"
#include "card.h"

void main() {
	std::srand(time(nullptr));
	setlocale(LC_ALL, "Norwegian");

	testOppg1Og2();
	testOppg3();
	testBlackJack();
}


