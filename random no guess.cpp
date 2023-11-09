#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    cout << "Welcome to Guess the Number!" << endl;
    cout << "I've chosen a number between 1 and 100. Can you guess it?" << endl;

    // Initialize the user's guess to an invalid number
    int userGuess = 0;

    // Keep asking for guesses until the user guesses the correct number
    while (userGuess != secretNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Provide feedback
        if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number, " << secretNumber << "!" << endl;
        }
}
}
