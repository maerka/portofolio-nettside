
// ------- *** ------- UI-class ------- *** -------
class UI{
    // Adds a new card to player's hand
    addPlayerCard(card){
        const UIcard = document.createElement('span');
        UIcard.classList.add('card','face-up');
        UIcard.appendChild(document.createTextNode(card.toStringShort()))
        const UIplayer = document.getElementById('player');
        UIplayer.appendChild(UIcard)
    }
    // Adds a new card to dealers's hand - faceDown true or false
    addDealerCard(card, faceDown){
        const UIcard = document.createElement('span');
        UIcard.className = 'card';
        UIcard.classList.add(faceDown? 'face-down': 'face-up');
        UIcard.appendChild(document.createTextNode(card.toStringShort()))

        const UIdealer = document.getElementById('dealer');
        UIdealer.appendChild(UIcard)
        // UIdealer.style.display = 'none'

    }
    // Make dealer's cards faceUp
    displayDealer(p){
        const cards = document.querySelectorAll('.face-down');
        cards.forEach(function(card){
            card.classList.replace('face-down','face-up')
        })
        this.dealerPoints(p);
    }
    // Display points of player
    playerPoints(p){
        const UIpoints = document.getElementById('points-player');
        UIpoints.innerHTML='Player: '+p;
    }
    // Display points of dealer
    dealerPoints(p){
        const UIpoints = document.getElementById('points-dealer');
        UIpoints.innerHTML=p;
    }
    // Handle gameOver. Display play-again - button
    winOrLoose(win){
        const btn = document.getElementById('restart-btn')
        btn.style.visibility ='';
        if(win){
            btn.innerHTML = 'You Won! Play again?';
            
        } else{
            btn.innerHTML = 'You Lost... Play again?';
            btn.className = 'loose';
        }
    }

    // Restart game when play-again button is pressed
    playAgain(){
        console.log('Game RESTART')
        document.location.reload()
    }
}

// ------- *** ------- BlackJack-class ------- *** -------
class BlackJack{
    constructor(){
        this.deck = new Deck();
        this.ui = new UI();
        this.playerHand = [];
        this.dealerHand = [];
        this.playerHandPoints = 0;
        this.dealerHandPoints = 0;
        this.playerCardsDrawn = 0;
        this.dealerCardsDrawn = 0;
        this.game = true;
        this.player11ace =0;
    }

    // Check if card is ACE
    isAce(card){
        return(card.getRank() === 1? true: false)
    }
    // Set card-value of drawn card according to game-rules
    getCardValue(card){
        if (this.isAce(card)){
            return -1;
        }
        else if (card.getRank() <=9){
            return card.getRank();
        }
        else if (card.getRank() <=13){
            return 10;
        }
        else{return 0}
    }

    // Set value of player's drawn card according to game-rules
    getPlayerCardValue(card){
        let value = this.getCardValue(card);
        if (value===-1){
            if (this.playerHandPoints<11){
                value=11;
                // Hand contains a new Ace of value 11
                this.player11ace+=1;
            } else{value=1}
        }
        return Number(value);
    }

    // Set value of dealer's drawn card according to game-rules
    getDealerCardValue(card){
    let value = this.getCardValue(card)
    if (value === -1 && this.dealerHandPoints <= 10){
        return 11}
    else if(value === -1 && this.dealerHandPoints > 10){
        return 1}
    else{
        return value}
    }

    // Player and dealer draw 2 cards each. 1 is faceDown. Set sum of card-values
    drawInitialCards(){
        //1st player card
        let card = this.deck.drawCard();
        this.playerHand.push(card);
        this.playerHandPoints += this.getPlayerCardValue(card);
        this.ui.addPlayerCard(card);
        
        //2nd player card
        card = this.deck.drawCard();
        this.playerHand.push(card);
        this.playerHandPoints += this.getPlayerCardValue(card);
        this.ui.addPlayerCard(card);

        // Display points of player
        this.ui.playerPoints(this.playerHandPoints);
        
        //1st dealer card
        card = this.deck.drawCard();
        this.dealerHand.push(card);
        this.dealerHandPoints += this.getDealerCardValue(card);
        this.ui.addDealerCard(card,false);

        // Display points of dealer's first card
        this.ui.dealerPoints(this.dealerHandPoints);
        
        //2nd dealer card
        card = this.deck.drawCard();
        this.dealerHand.push(card);
        this.dealerHandPoints += this.getDealerCardValue(card);
        this.ui.addDealerCard(card,true);
    }

    // Logic behind new-card-button
    drawNewCard(){
        // Draw card
        let card = this.deck.drawCard();
        this.playerHand.push(card);
        this.ui.addPlayerCard(card);
        // Add card value
        this.playerHandPoints +=this.getPlayerCardValue(card);
        this.ui.playerPoints(this.playerHandPoints);
        
        // Dealer draws only if player draws and dealer's points is below 17
        if (this.dealerHandPoints<17){
            card = this.deck.drawCard();
            this.dealerHand.push(card);
            this.dealerHandPoints += this.getDealerCardValue(card);
            this.ui.addDealerCard(card,true);
        }
        this.checkPoints();
    }

    // Logic behind showCards-button
    showCards(){
        this.game = false;
        this.gameOver();
    }
    // Check for win or loose after cards are drawn
    checkPoints(){
        if(this.playerHandPoints>21){
            // Check for ACEs: They can have value 1 or 11
            if(this.player11ace>0){
                this.playerHandPoints-=10;
                this.player11ace-=1;
                this.ui.playerPoints(this.playerHandPoints)
                this.checkPoints();
            }             
        } 
        // Check for ACEs: They can have value 1 or 11
        else if(this.dealerHandPoints>21){
            if(this.dealer11ace>0){
                this.dealerHandPoints-=10;
                this.dealer11ace-=1;
                this.ui.playerPoints(this.dealerHandPoints)
                this.checkPoints();
            }             
        }         
        // If no aces and value is above 21
        if(this.playerHandPoints>21 || this.dealerHandPoints >21){
            this.game = false; 
            this.gameOver();            
        } 
    }

    // Determine win or lose and update graphics
    gameOver(){
        this.ui.displayDealer(this.dealerHandPoints);
        console.log('GAME IS OVER');
        console.log('Your points:', this.playerHandPoints);
        console.log('Dealer\'s points:', this.dealerHandPoints);
        if (this.playerHandPoints>21){
            console.log('You Lost')
            this.ui.winOrLoose(false);}
            
        else if (this.dealerHandPoints>21){
            console.log('You Won')
            this.ui.winOrLoose(true);}
        else if (this.playerHandPoints>this.dealerHandPoints){
            console.log('You Won')
            this.ui.winOrLoose(true);}
        else if (this.playerHandPoints <= this.dealerHandPoints){
            console.log('You Lost')
            this.ui.winOrLoose(false);}
        else if (this.playerHandPoints === this.dealerHandPoints){
            if(this.dealerHand.length > 2 && this.playerHand.length===2){
                console.log('You Won');
                this.ui.winOrLoose(true);}
            else{ console.log('You Lost')
            this.ui.winOrLoose(false);}
            }
    }

}


// ------- *** ------- EVENT-LISTENERS and GAME LOGICS ------- *** -------
game = new BlackJack();
const newCardBtn = document.getElementById('new-card-btn');
const showBtn = document.getElementById('show-btn');
const restartBtn = document.getElementById('restart-btn');

// game.playGame();
game.deck.shuffle();
game.drawInitialCards();


//Eventlistener for "NewCard"
newCardBtn.addEventListener('click', function(){game.drawNewCard()});
//Eventlistener for "showCards"
showBtn.addEventListener('click',function(){game.showCards()});
//Eventlistener for "NewCard"
restartBtn.addEventListener('click',function(){game.ui.playAgain()});



// ---------------TESTING OF BLACKJACK-CLASS -------------------
// const card1 = game.deck.allCards[0];
// const card2 = game.deck.allCards[3];
// const card3 = game.deck.allCards[11];
// const card4 = game.deck.allCards[15];
// console.log(card1.toString());
// console.log(card2.toString());
// console.log(card3.toString());
// console.log(card4.toString());

// console.log(card1);
// console.log(game.isAce(card1));
// console.log(game.getCardValue(card1));
// console.log(game.getCardValue(card2));
// console.log(game.getCardValue(card3));
// console.log(game.getCardValue(card4));

// const value2 =game.getPlayerCardValue(card2)
// console.log(value2, typeof(value2));

// game.dealerHandPoints=0;
// console.log('dealers card value:', game.getDealerCardValue(card2))
// game.showPlayersHand();
// game.showDealersHand();
// game.drawInitialCards();


// ------------------- TESTING OF UI-CLASS -------------------
// const card1 = game.deck.allCards[0];
// const card2 = game.deck.allCards[3];
// const card3 = game.deck.allCards[11];
// const card4 = game.deck.allCards[15];

// let myUI = new UI();
// myUI.addPlayerCard(card1);