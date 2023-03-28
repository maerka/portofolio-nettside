import random
from Cards import Card
from Cards import Suits
from Cards import Rank

class Deck:
    def __init__(self):
        self.cardsInDeck = 0
        self.currentCardIndex = 0
        self.allCards = self.buildDeck()
        
    
    def buildDeck(self):
        #allCards = {}
        allCards = []
        for s in Suits:
            for r in Rank:
                #card1 = Card(r,s)
                allCards.append(Card(r,s))
                self.cardsInDeck += 1
        #print(f'There are {self.cardsInDeck} cards in the deck. ')
        return allCards
    
    def getCurrentCardIndex(self):
        return self.cardsInDeck
    
    def showCards(self):
        for card in self.allCards:
            print(card)
            
    def showCardsShort(self):
        for card in self.allCards:
            print(card.toStringShort())
            
    def swap(self, c1, c2):
        temp1 = self.allCards[c1-1]
        temp2 = self.allCards[c2-1]
        self.allCards[c1-1] = temp2
        self.allCards[c2-1] = temp1
        
    def shuffle(self):
        random.shuffle(self.allCards)
        
    def drawCard(self):
        self.currentCardIndex +=1
        return self.allCards[self.currentCardIndex-1]
        
            
            
# TESTING CLASSES    
# myDeck = Deck()
# print('cards in deck:',myDeck.getCurrentCardIndex())

# myDeck.swap(1,2)
# myDeck.shuffle()
# myDeck.showCardsShort()

# for i in range(5):
#     print(myDeck.drawCard())
        