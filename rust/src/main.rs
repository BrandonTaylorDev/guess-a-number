use std::io::{self, Write};
use rand::Rng;

fn gen_secret_number() -> i32 {
  rand::thread_rng().gen_range(0..10)
}

fn get_user_guess() -> i32 {
  let mut input = String::new();
  let guess: i32;

  println!("Guess a number between 0 and 9 (inclusive):");
  print!("> ");
  io::stdout().flush().unwrap_or_default();

  match io::stdin().read_line(&mut input) {
    Ok(_) => {},
    Err(err) => {
      println!("Error: {}", err);
    },
  };

  match input.trim().parse::<i32>() {
    Ok(num) => {
      guess = num;
      return guess;
    },
    Err(_) => {
      println!("That's not a number. Don't worry, I'll generate one for you.");
      guess = rand::thread_rng().gen_range(0..10);
      println!("Your guess: {}", guess);
    }
  }

  return guess;
}

fn main() {
  let secret = gen_secret_number();
  let mut guess = get_user_guess();

  loop {
    match guess.cmp(&secret) {
      std::cmp::Ordering::Less    => println!("Too low!"),
      std::cmp::Ordering::Greater => println!("Too high!"),
      std::cmp::Ordering::Equal   => {
        println!("You got it!");
        break;
      }
    }

    guess = get_user_guess();
  }
}
