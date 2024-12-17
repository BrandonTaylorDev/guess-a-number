package main

import (
	"fmt"
	"math/rand"
	"strconv"
)

func genSecret() int {
	return rand.Intn(10)
}

func getUserGuess() int {
	var input string = ""
	var guess int

	fmt.Println("Guess a number between 0 and 9 (inclusive):")
	fmt.Print("> ")

	_, err := fmt.Scanln(&input)
	if err != nil {
		fmt.Println("Error reading input", err)
	}

	guess, err = strconv.Atoi(input)
	if err != nil {
		fmt.Println("That's not a number. Don't worry, I'll generate one for you.")
		guess = rand.Intn(10)
		fmt.Println("Your guess:", guess)
	}

	return guess
}

func main() {
	var secret = genSecret()
	var guess = getUserGuess()

	for {
		if guess == secret {
			println("You got it!")
			break
		}

		if guess > secret {
			println("Too high")
		} else {
			println("Too low")
		}

		guess = getUserGuess()
	}
}
