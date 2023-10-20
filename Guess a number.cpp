#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    int number = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout<< "Welcome to Guess a Number Game." <<endl;
    cout<< "I have selected a random number between 1 and 100. Guess it." <<endl;

    while (true) {
        cout<< "Enter your guess: ";
        cin>> guess;
        attempts++;

        if (guess < number) {
            cout<< "Low! Try again." <<endl;
        } else if (guess > number) {
            cout<< "High! Try again." <<endl;
        } else {
            cout<< "Excellent! You guessed it" << number << "in" << attempts << "attempts." <<endl;
            break;
        }
    }

    return 0;
}

