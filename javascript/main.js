const readline = require('readline');
const { randomInt } = require('crypto');

// wrap in async function.
(async function() {

  function genSecret() {
    return Math.floor(Math.random() * 10);
  }
  
  function getUserGuess() {
    return new Promise((resolve) => {
      const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      });
  
      console.log("Guess a number between 0 and 9 (inclusive):");
      process.stdout.write("> ");
  
      rl.question('', (input) => {
        let guess = parseInt(input, 10);
  
        if (isNaN(guess)) {
          console.log("That's not a number. Don't worry, I'll generate one for you.");
          guess = randomInt(0, 10);
          console.log(`Your guess: ${guess}`);
        }
  
        rl.close();
        resolve(guess);
      });
    });
  }

  let secret = genSecret();
  let guess = await getUserGuess();

  while (true) {
    if (guess === secret) {
      console.log("You got it!");
      break;
    }

    if (guess > secret) {
      console.log("Too high!");
    } else {
      console.log("Too low!");
    }

    guess = await getUserGuess();
  }
})();
