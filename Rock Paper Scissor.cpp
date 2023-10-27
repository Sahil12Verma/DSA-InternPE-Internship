#include <iostream>
#include <cstdlib>
#include <ctime>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3
using namespace std;

int main() {
    int playerChoice, computerChoice;

    srand(time(0));

    cout << "Let's play Rock, Paper, Scissor!\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissor\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> playerChoice;

    computerChoice = rand() % 3 + 1;

    cout << "Computer chose: ";
    switch (computerChoice) {
        case 1:
            cout << "Rock";
            break;
        case 2:
            cout << "Paper";
            break;
        case 3:
            cout << "Scissor";
            break;
    }
    cout << endl;

    if (playerChoice == computerChoice) {
        cout << "TIE!\n";
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }

    return 0;
}
