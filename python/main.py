import random

def gen_secret():
    return random.randint(0, 9)

def get_user_guess():
    print("Guess a number between 0 and 9:")
    print("> ", end="")
    guess = input()
    
    try:
      guess = int(guess)
    except ValueError:
      print("Tha's not a number. Don't worry, I'll generate one for you.")
      guess = random.randint(0, 9)
      print(f"Your guess: {guess}")
    
    return guess
      
      

if __name__ == '__main__':
  secret = gen_secret()
  guess = get_user_guess()
  
  while True:
    if guess == secret:
      print("You got it!")
      break
    elif guess < secret:
      print("Too low!")
    else:
      print("Too high!")
    
    guess = get_user_guess()
