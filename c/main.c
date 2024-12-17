#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int gen_secret() {
    return rand() % 10;
}

int get_user_guess() {
  int guess;
  char input[100];

  printf("Guess a number between 0 and 9 (inclusive):\n> ");
  if (fgets(input, sizeof(input), stdin) != NULL) {
    
    if (sscanf(input, "%d", &guess) != 1) {
      printf("That's not a number. Don't worry, I'll generate one for you.\n");
      guess = rand() % 10;
      printf("Your guess: %d\n", guess);
    }
  } else {
    guess = rand() % 10;
    printf("Input error. Generating a guess for you: %d\n", guess);
  }

  return guess;
}

int main() {
  int secret, guess;

  srand(time(NULL));

  secret = gen_secret();

  guess = get_user_guess();

  while (1) {
    if (guess == secret) {
      printf("You got it!\n");
      break;
    } else if (guess < secret) {
      printf("Too low!\n");
    } else {
      printf("Too high!\n");
    }

    guess = get_user_guess();
  }

  return 0;
}
