'use strict';
let score = 20;
let SecretNumber = Math.floor(Math.random() * 20) + 1;
let highscore = 0;
const displayMessage = function (message) {
  document.querySelector('.message').textContent = message;
};

document.querySelector('.again').addEventListener('click', function () {
  document.querySelector('body').style.backgroundColor = '#222';
  score = 20;
  document.querySelector('.score').textContent = score;
  document.querySelector('.guess').value = '';
  SecretNumber = Math.floor(Math.random() * 20) + 1;
  console.log(SecretNumber);
  document.querySelector('.message').textContent = 'start guessing';
});
document.querySelector('.check').addEventListener('click', function () {
  const guess = Number(document.querySelector('.guess').value);
  if (!guess) {
    //no number
    if (score > 0) {
      //   document.querySelector('.message').textContent = '⛔No Number!';
      displayMessage('⛔No Number!');
      score--;
      document.querySelector('.score').textContent = score; //updates the score
    } else {
      document.querySelector('.message').textContent = 'You Lost the game';
      document.querySelector('body').style.backgroundColor = '#ff1177'; //loses the game when the score is less than 0
    }
  }
  //correct number
  else if (guess === SecretNumber) {
    // document.querySelector('.message').textContent = 'Correct Number';
    displayMessage('Correct Number');
    if (score > highscore) {
      highscore = score;
      document.querySelector('.highscore').textContent = highscore;
    }
    //updates the score
    document.querySelector('body').style.backgroundColor = '#60b347';
    document.querySelector('.number').style.width = '30rem';
    document.querySelector('.number').textContent = SecretNumber;
  }
  //if guess is not equal to secret number
  else if (guess !== SecretNumber) {
    if (score > 0) {
      displayMessage(
        guess > SecretNumber
          ? 'Too high than the secret number'
          : 'too low than the secret number'
      );
      //if the guess is too high or too low than the secret number
      score--;
      document.querySelector('.score').textContent = score; //updates the score
    } else {
      displayMessage('you lost the game');
      document.querySelector('body').style.backgroundColor = '#ff1177'; //loses the game when the score is less than 0
    }
  }
});
