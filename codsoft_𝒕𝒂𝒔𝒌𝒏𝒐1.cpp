#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int secretNumber = std::rand() % 100 + 1;

    std::cout << "Welcome to the Guess the Number game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100. Can you guess it?" << std::endl;

    int userGuess;

    do {
        
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the number." << std::endl;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }
    } while (userGuess != secretNumber);

    return 0;
}
