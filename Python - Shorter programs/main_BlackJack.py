from CardDeck import Deck
from Cards import Rank
from Cards import Suits

class BlackJack:
    def __init__(self):
        self.deck = Deck()
        self.playerHand = []
        self.dealerHand = []
        self.playerHandPoints = int(0)
        self.dealerHandPoints = int(0)
        self.playerCardsDrawn = 0
        self.dealerCardsDrawn = 0
        
    def isAce(self, card):       
        if card.getRank() == Rank.ACE:
            return True
        else:
            return False
        
    def getCardValue(self, card):
        if self.isAce(card):
            return -1
        elif card.r.value <= 9:
            return card.r.value
        elif card.r.value <= 13:
            return 10
        else:
            return 0
 
    def getPlayerCardValue(self, card):
        value = self.getCardValue(card)
        if value == -1:
            value = int(input('1 or 11?'))
            while value != 1 and value !=11:
                print('write 1 or 11')
                value = int(input('1 or 11?'))
            return value
        else:
            return value
        # temp = self.playerHandPoints
        # self.playerHandPoints += value
        # temp = self.playerHandPoints
        # print('nice')
        
    def getDealerCardValue(self, card):
        value = self.getCardValue(card)
        if value == -1 and self.dealerHandPoints <= 10:
            return 11
        elif value == -1 and self.dealerHandPoints > 10:
            return 1
        else:
            return value
        
    def showPlayerHands(self):
        print('Player\'s hand:')
        for i in self.playerHand:
            print(i.toStringShort())
        
    def showDealerHands(self):
        print('Dealer\'s hand:')
        for i in self.dealerHand:
            print(i.toStringShort())
              
            
 
    def drawInititalCards(self):
        #1st player card
        card = self.deck.drawCard()
        print('Your 1st card:',card.toStringShort())
        self.playerHand.append(card)
        self.playerHandPoints += self.getPlayerCardValue(card)
        # print('your value:', self.playerHandPoints)

        #2nd player card
        card = self.deck.drawCard()
        print('Your 2nd card:',card.toStringShort())
        self.playerHand.append(card)
        self.playerHandPoints += self.getPlayerCardValue(card)
        # print('your value:', self.playerHandPoints)
        
        
        #1st dealer card
        card = self.deck.drawCard()
        print('Dealers 1st card:',card.toStringShort())
        self.dealerHand.append(card)
        self.dealerHandPoints += self.getDealerCardValue(card)
        # print('Dealer value:', self.dealerHandPoints)

        #2nd dealer card
        card = self.deck.drawCard()
        # print('Dealers 2nd card:',card.toStringShort())
        self.dealerHand.append(card)
        self.dealerHandPoints += self.getDealerCardValue(card)  
        # print('Dealer value:', self.dealerHandPoints)
        
    
    def askPlayerDrawCard(self):
        answer = input('Do you want to draw a card? (y/n)')
        while answer != 'y' and answer != 'n':
            print("write y or n")
            answer = input('Do you want to draw a card? (y/n)')
        if answer == 'y':
            return True
        if answer == 'n':
            return False
            
    def playGame(self):
        game = True
        self.deck.shuffle()
        self.drawInititalCards()
        
        while game:
            if self.askPlayerDrawCard():
                card = self.deck.drawCard()
                self.playerHand.append(card)
                self.showPlayerHands()
                self.playerHandPoints += self.getPlayerCardValue(card)
                
                if self.dealerHandPoints <17:
                    card = self.deck.drawCard()
                    self.dealerHand.append(card)
                    self.dealerHandPoints += self.getDealerCardValue(card)
            else:
                game = False
                
            if self.playerHandPoints > 21 or self.dealerHandPoints > 21:
                game = False
                
        
        print('\nGAME IS OVER')
        self.showPlayerHands()
        print('your value:', self.playerHandPoints)
        self.showDealerHands()
        print('Dealer value:', self.dealerHandPoints)
        
        
        print('\n')
        if self.playerHandPoints > 21:
            print('Du tapte')
        elif self.dealerHandPoints > 21:
            print('Du Vant')
        elif self.playerHandPoints > self.dealerHandPoints:
            print('Du vant')
        elif self.playerHandPoints <= self.dealerHandPoints:
            print('Du tapte')
        elif self.playerHandPoints == self.dealerHandPoints:
            if len(self.dealerHand) > 2 and len(self.playerHand) ==2:
                print('Du vant')
            else:
                print('Du tapte')
        

game = BlackJack().playGame()
