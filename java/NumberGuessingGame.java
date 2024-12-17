import java.util.Random;
import java.util.Scanner;

public class NumberGuessingGame {

  public static int genSecret() {
    Random random = new Random();
    return random.nextInt(10);
  }

  public static int getUserGuess() {
    Scanner scanner = new Scanner(System.in);
    Random random = new Random();

    System.out.println("Guess a number between 0 and 9 (inclusive):");
    System.out.print("> ");

    String input = scanner.nextLine();
    int guess;

    try {
      guess = Integer.parseInt(input);
    } catch (NumberFormatException e) {
      System.out.println("That's not a number. Don't worry, I'll generate one for you.");
      guess = random.nextInt(10);
      System.out.println("Your guess: " + guess);
    }

    return guess;
  }

  public static void main(String[] args) {
    int secret = genSecret();
    int guess = getUserGuess();

    while (true) {
      if (guess == secret) {
        System.out.println("You got it!");
        break;
      } else if (guess < secret) {
        System.out.println("Too low!");
      } else {
        System.out.println("Too high!");
      }

      guess = getUserGuess();
    }
  }
}
