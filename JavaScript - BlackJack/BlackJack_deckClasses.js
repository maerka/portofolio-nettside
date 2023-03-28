
// ----- *** ----- ENUM - CARD RANK AND SUIT ----- *** -----

// Suits "enum"
const Suits={
    CLUB: 'Club',
    HEART: 'Heart',
    DIAMOND: 'Diamond',
    SPADE:'Spade'
}


// Rank "enum" is an object
const Rank={
    ACE: 1,
    TWO: 2,
    THREE: 3,
    FOUR: 4,
    FIVE: 5,
    SIX: 6,
    SEVEN: 7,
    EIGHT: 8,
    NINE: 9,
    TEN: 10,
    KNIGHT: 11,
    QUEEN: 12,
    KING: 13
}

// Return key of the value as a string
function rankToString(value){
    const allKeys = Object.keys(Rank) //'ACE', 'TWO',..., 'KNIGHT', 'QUEEN', 'KING'
    if (value>0 && value <14){
        return allKeys[value-1]
    } else
        {return 'invald value'}
}


// ----- *** ----- CARD-Class ----- *** -----
class Card{
    constructor(Rank, Suits){
        this.r = Rank; //Integer 12
        this.s = Suits; // 'Spade'
        this.valid = true; //boolean
    }
    toString(){ //Returns Queen of hearts
        return(`${rankToString(this.r)} of ${this.s}`);  
    }
    toStringShort(){ // returns QH
        let r = this.getRank();
        if (r===1){
            r='A';
        } else if(r===11){
            r='J'
        }else if(r===12){
            r='Q'
        }else if(r===13){
            r='K'
        }
        return `${r}${this.getSuit()[0]}`;
    }

    getRank(){
        return this.r; //12
    }
    getSuit(){
        return this.s; //Heart
    }
    validation(){
        return this.valid; //true
    }
}

// ----- *** ----- DECK-Class ----- *** -----
class Deck{
    constructor(){
        this.cardsInDeck = 0;
        this.currentCardIndex = 0;
        this.allCards = this.buildDeck();
    }

    buildDeck(){
        let allCards = [];
        for (let s in Suits){
            for (let r in Rank){
                this.cardsInDeck+=1;
                allCards.push(new Card(Rank[r],s));                
                
            }
        }
        // console.log(`A deck of ${this. cardsInDeck} cards was created`)
        return allCards
    }
    getCurrentCardIndex(){
        return this.currentCardIndex;
    }
    // Show in console.log "Queen of Hearts"
    showCards(){
        this.allCards.forEach(function(card){
            console.log(card.toString());
        })
    }
    // Show in console.log "QH"
    showCardsShort(){
        this.allCards.forEach(function(card){
            console.log(card.toStringShort());
        })
    }

    // Swap 2 cards of cardIndex c1 and c2. First card in the deck has index 1 not 0
    swap(c1, c2){
        if (c1 <= this.cardsInDeck && 
            c2 <= this.cardsInDeck &&
            c1 >=0 && c2){
        let temp1 = this.allCards[c1-1];
        let temp2 = this.allCards[c2-1];
        this.allCards[c1-1] = temp2;
        this.allCards[c2-1] = temp1;
        }
        else{alert('Error in Deck.swap(). check c1 and c2')}
    }
        
    shuffle(){
        //https://dev.to/codebubb/how-to-shuffle-an-array-in-javascript-2ikj
        for(let i = this.cardsInDeck-1; i>0;i--){
            const j = Math.floor(Math.random() * (i + 1));
            const temp = this.allCards[i];
            this.allCards[i] = this.allCards[j];
            this.allCards[j] = temp;
        }
    }
    drawCard(){
        this.currentCardIndex +=1;
        return this.allCards[this.currentCardIndex-1];
    }
}


// ----- *** ----- TESTING OF DECK-CLASS ----- *** -----

// const deck = new Deck();
// deck.showCards();
// // deck.showCardsShort();

// const card = deck.allCards;
// deck.swap(51,52);
// deck.shuffle();
// console.log('');
// deck.showCardsShort();

// console.log('Drawing cards');
// console.log(deck.drawCard().toString());
// console.log(deck.drawCard().toString());
// console.log(deck.drawCard().toString());
// console.log(deck.drawCard().toString());



// // TESTING OF CARD-CLASS
// const card1 = new Card(Rank.ACE, Suits.SPADE)
// const card2 = new Card(Rank.FIVE, Suits.HEART)
// const card3 = new Card(Rank.QUEEN, Suits.HEART)
// const type = card1.toString();
// const r1 = Rank.ACE;
// const r2 = Rank.FIVE;

// console.log(r1+r2);
// console.log(card1);
// console.log(type);

// console.log(card1.toStringShort());
// console.log(card2.toStringShort());
// console.log(card3.toStringShort());
// console.log(card3.validation())

// const allKeys = Object.keys(Rank) 

// for (let r in Rank){
//     console.log(Rank[r])
// }