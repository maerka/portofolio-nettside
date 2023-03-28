/*
GAME FUNCTION:
- Player must guess a number between a min and max
- Player gets a certain amount of guesses
- Notify player of guesses remaining
- Notify the player of the correct answer if loose
- Let player choose to play again
*/

// Game values
let min = 1, 
    max = 10,
    winningNum = Math.floor(Math.random()*(max-min+1)+min)
    guessesLeft = 3;

console.log(winningNum)

// UI Elements
const   game = document.querySelector('.game'),
     // game = document.getElementById('game'), //Similar to the one above
        minNum = document.querySelector('.min-num'),
        maxNum = document.querySelector('.max-num'),
        guessBtn = document.querySelector('#guess-btn'),
        guessInput = document.querySelector('#guess-input'),
        message = document.querySelector('.message'),
        UIguessesLeft = document.querySelector('.guess-left');

// Assign UI min and max
minNum.textContent = min;
maxNum.textContent = max;
UIguessesLeft.textContent = guessesLeft;

// Play again event listener
let t = game;

game.addEventListener('mousedown', function(e){
    if (e.target.className === 'play-agian'){
        // Reload the page
        window.location.reload();
    }
})


// Listen for guess
guessBtn.addEventListener('click', function(){
    let guess = parseInt(guessInput.value);
    // Invalid number
    if (isNaN(guess) || guess < min || guess > max) {
        setMessage(`Please enter a number between ${min} and ${max}`, 'red');
    }
    // Valid number
    else{
        guessCounter();
        // Game over - won
        if(guess === winningNum){
            gameOver(true, `You Win! ${winningNum} is correct`);
        // Game over - loose
        }
        else if (guessesLeft === 0){
            gameOver(false, `You lost! The correct number was ${winningNum}`);
        }
        // Game continues
        else{
            setMessage ('','black')
            guessInput.value ='';
            guessInput.style.borderColor = 'red';

        }
    }   
})

// Set message
function setMessage(msg, color){
    message.style.color = color
    message.textContent = msg;
}

// Update guessesLeft
function guessCounter(){
    guessesLeft -= 1;
    UIguessesLeft.textContent = guessesLeft;
    return guessesLeft
}

// Game over - won or lost
function gameOver(won, msg){
    let color;
    won === true ? color = 'green': color = 'red';

    //Disable input
    guessInput.disabled = true;
    // Change border color
    guessInput.style.borderColor = color;
    // Change text color
    message.style.color = color;
    // Set message
    setMessage(msg);
    // Set button message
    guessBtn.value = "Play again?";
    guessBtn.className = 'play-agian';
}

