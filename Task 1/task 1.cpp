#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void numberGuessingGame() {
    srand(time(0));
    int number_to_guess = rand() % 100 + 1;
   
    int guess = 0;
    int attempts = 0;
    cout << "\n\t\t=====================================" << endl;
    cout << "\n\t\tWelcome to the Number Guessing Game!" << endl;
    cout << "\n\t\t=====================================" << endl;
    cout << "\n\tI have selected a number between 1 and 100." << endl;
    cout << "\n\t\tYour task is to guess it!" << endl;
    while (true) {
        cout << "\tGuess a number between 1 and 100: ";
        cin >> guess;
        attempts++;
        if (guess < number_to_guess) {
        	system("cls");
        	cout << "\n\t\t======================" << endl;
        	cout << "\n\t\tNumber Guessing Game!" << endl;
        	cout << "\n\t\t======================" << endl;
            cout << "\n\n\n\t\tToo low! Try again." << endl;
            
        }
        else if (guess > number_to_guess) {
        	system("cls");
        	cout << "\n\t\t======================" << endl;
        	cout << "\n\t\tNumber Guessing Game!" << endl;
        	cout << "\n\t\t======================" << endl;
            cout << "\n\n\n\t\tToo high! Try again." << endl;
            
        }
        else {
            cout << "\n\n\tCongratulations! You've guessed the correct number: " << number_to_guess << endl;
            cout << "\nIt took you " << attempts << " attempts to guess correctly." << endl;
            break; 
        }
    }
}int main() {
    numberGuessingGame();
    return 0;
}