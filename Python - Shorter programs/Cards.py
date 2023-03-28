# https://codereview.stackexchange.com/questions/185044/using-enums-in-a-card-deck-class
# OVING 5
from enum import Enum 

class Suits(Enum):
    CLUB = 1
    HEART = 2
    DIAMOND = 3
    SPADE = 4
    
class Rank(Enum):
    ACE = 1
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5
    SIX = 6
    SEVEN = 7
    EIGHT = 8
    NINE = 9
    TEN = 10
    KNIGHT = 11
    QUEEN = 12
    KING = 13
  
    
class Card:
    def __init__(self, Rank, Suits):
        self.r = Rank
        self.s = Suits
        self.invalid = True
        
    def __str__(self):
        #return f'{self.r.name} of {self.s.name}'  
        return '{} of {}'.format(self.r.name, self.s.name)
 
    def rankToString(self):
        return self.r.name
    
    def getRank(self):
        return self.r
    
    def suitToString(self):
        return self.s.name
    
    def getSuit(self):
        return self.s
    
    def toStringShort(self):
        return f'{self.r.value}{self.s.name[0]}'
    
    def valid(self):
        return self.invalid

#TEST OF CLASSES
# card1 = Card(Rank.KNIGHT,Suits.HEART)
# print('1:', card1)                #KNIGHT of HEART
# print('2: ',card1.rankToString()) #KNIGHT
# print('3: ',card1.getRank())      #Rank.KNIGHT
# print('4: ',card1.suitToString()) #HEART
# print('5: ',card1.getSuit())      #Suits.HEART
# print('6: ',card1.toStringShort())#11H
# print('7: ',card1.valid())        #True

    






