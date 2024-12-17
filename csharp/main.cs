using System;

class GuessANumber
{
  static Random random = new Random();

  static int GenSecret()
  {
    return random.Next(0, 10);
  }

  static int GetUserGuess()
  {
    int guess;
    string input;

    Console.WriteLine("Guess a number between 0 and 9 (inclusive):");
    Console.Write("> ");
    input = Console.ReadLine();

    if (!int.TryParse(input, out guess))
    {
      Console.WriteLine("That's not a number. Don't worry, I'll generate one for you.");
      guess = random.Next(0, 10);
      Console.WriteLine("Your guess: " + guess);
    }

    return guess;
  }

  static void Main()
  {
    int secret, guess;

    secret = GenSecret();
    guess = GetUserGuess();

    while (true)
    {
      if (guess == secret)
      {
        Console.WriteLine("You got it!");
        break;
      }
      else if (guess < secret)
      {
        Console.WriteLine("Too low!");
      }
      else
      {
        Console.WriteLine("Too high!");
      }

      guess = GetUserGuess();
    }
  }
}
