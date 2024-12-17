#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

int gen_secret() {
    return rand() % 10;
}

int get_user_guess() {
    int guess;
    std::string input;

    std::cout << "Guess a number between 0 and 9 (inclusive):\n> ";
    std::getline(std::cin, input);
    
    std::stringstream ss(input);
    if (!(ss >> guess)) {
        std::cout << "That's not a number. Don't worry, I'll generate one for you.\n";
        guess = rand() % 10;
        std::cout << "Your guess: " << guess << std::endl;
    }

    return guess;
}

int main() {
    int secret, guess;

    srand(time(NULL));

    secret = gen_secret();

    guess = get_user_guess();

    while (true) {
        if (guess == secret) {
            std::cout << "You got it!" << std::endl;
            break;
        } else if (guess < secret) {
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Too high!" << std::endl;
        }

        guess = get_user_guess();
    }

    return 0;
}
