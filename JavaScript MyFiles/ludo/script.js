'use strict';
//selecting elements
const score1 = document.getElementById('score--0');
const score2 = document.querySelector('#score--1');
const btnNew = document.querySelector('.btn--new');
const btnRoll = document.querySelector('.btn--roll');
const btnHold = document.querySelector('.btn--hold');
const scoreDisplay = document.querySelector('.current-score');
const player0 = document.querySelector('.player--0');
const player1 = document.querySelector('.player--1');

const dice = document.querySelector('.dice');

dice.classList.add('hidden');
const scores = [0, 0];
let currentScore = 0;
let activePlayer = 0;
score2.textContent = 0;
score1.textContent = 0;
//rolling dice functionality

btnRoll.addEventListener('click', function () {
  //generating random dice roll
  let randomdice = Math.floor(Math.random() * 6 + 1);
  //switching the player

  function switchPlayer() {
    //switch the active player
    document.getElementById(`current--${activePlayer}`).textContent = 0;

    activePlayer = activePlayer === 0 ? 1 : 0;
    player0.classList.toggle('player--active');
    player1.classList.toggle('player--active');
  }
  //display dice
  dice.classList.remove('hidden');
  dice.src = `dice-${randomdice}.png`;
  //check for rolled 1:: if true, swith to next player

  //adding to the current score
  if (randomdice !== 1) {
    currentScore += randomdice;
    document.getElementById(`current--${activePlayer}`).textContent =
      currentScore;
  } else {
    switchPlayer();
  }

  btnHold.addEventListener('click', function () {
    //1 add current score to active player's score
    scores[activePlayer] = currentScore + scores[activePlayer];
    document.getElementById(`score--${activePlayer}`).textContent =
      scores[activePlayer];
    currentScore = 0;

    if (scores[activePlayer] >= 100) {
      alert(`Player ${activePlayer + 1} is th winner`);
    }
    switchPlayer();
    //check if player's score is
    //finish the game
    //switch to next player
  });
});
