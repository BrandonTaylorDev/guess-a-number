<?php
  function gen_secret() {
      return rand(0, 9);
  }

  function get_user_guess() {
      echo "Guess a number between 0 and 9 (inclusive):\n> ";
      $guess = trim(fgets(STDIN));

      if (!is_numeric($guess)) {
          echo "That's not a number. Don't worry, I'll generate one for you.\n";
          $guess = rand(0, 9);
          echo "Your guess: $guess\n";
      } else {
          $guess = (int)$guess;
      }

      return $guess;
  }

  $secret = gen_secret();
  $guess = get_user_guess();

  while (true) {
      if ($guess == $secret) {
          echo "You got it!\n";
          break;
      } elseif ($guess < $secret) {
          echo "Too low!\n";
      } else {
          echo "Too high!\n";
      }

      $guess = get_user_guess();
  }
?>
