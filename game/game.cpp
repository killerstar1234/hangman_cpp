#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>

#include "giveInstructions.h"
#include "checkmatch.h"
#include "gameover.h"
#include "displayGuess.h"

using namespace std;

void game(string word) {
    // This is the guessing word
    vector<char> wordGuess(word.length());

    // THis is a array for used words
    vector<string> usedWords;

    // This is a array for used characters
    vector<char> usedChar;

    // Keeps track of how many guesses the player has used
    int guesses = 0;
    
    // The option we are on
    int option = 0;

    // The ammount of hints used
    int givenHints = 0;
    int usedHints = 0;

    // Math for givenHints
    if(word.length() > 2) {
        givenHints = word.length() / 3;
    }

    // Display the options
    giveInstructions();

    // Display the size of the word
    wordDisplay(wordGuess);

    while (option != 7) {

        // Ask for option
        cout << "Option: ";

        // Get the option
        cin >> option;

        if(cin.fail()) {
            cout << "Error: Enter A Number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (option > 7 || option <= 0) {
            cout << "That number Is not a option. Choose a option between 1 - 6." << endl;
        } else {

            if(option == 1) {
                // Guess a Character

                wordDisplay(wordGuess);


                char c;
                string inputChar;
                cout << "Guess A Character: ";
                cin >> inputChar;

                if(inputChar.length() == 1) {
                    c = inputChar[0];
                } else {
                    cout << "Enter 1 Character Please!" << endl;
                    continue;
                }

                // Change to lowercase
                c = tolower(c);

                bool letterFound = false;

                // Loop through the word and check if any characters match, if so replace them in the word guess
                for(size_t i = 0; i < word.length(); i++) {
                    if(word[i] == c) {
                        wordGuess[i] = word[i];
                        cout << "Found Letter!" << endl;
                        letterFound = true;
                    }
                }

                if(!letterFound) {
                    usedChar.push_back(c);
                    guesses++;
                    cout << "No Letter Found." << endl;
                }

                string guessString(wordGuess.begin(), wordGuess.end());

                // Check Match right here
                if(match(guessString, word)) {
                    cout << "You Won! Word Was: " << word << endl;
                    break;
                }

            } else if(option == 2) {
                // Guess the word

                wordDisplay(wordGuess);

                string wordInputGuess;

                cout << "Guess A Word: ";
                cin >> wordInputGuess;

                for (size_t i = 0; i < wordInputGuess.length(); ++i) {
                    wordInputGuess[i] = tolower(wordInputGuess[i]);
                }


                if(wordInputGuess.length() > word.length()) {
                    cout << "Your Guess was To Long!" << endl;
                    continue;
                } else if(wordInputGuess.length() < word.length()) {
                    cout << "Your Guess was To Short!" << endl;
                } else {
                    // check if they match
                    if(wordInputGuess == word) {
                        cout << "You Won! Word was: " << word << endl;
                        break;
                    } else {
                        guesses++;
                        usedWords.push_back(wordInputGuess);
                        cout << "Incorrect Guess" << endl;
                    }
                }
                

            } else if(option == 3) {
                // Get a hint

                // The word length has to be greater than 2
                // You get 1/3 word hints of the word

                if(givenHints > 0) {
                    // If we find a null variable spot in wordGuess then we will replace it and
                    for(size_t i = 0; i < wordGuess.size(); ++i) {
                        if(wordGuess[i] == '\0') {
                            wordGuess[i] = word[i];
                            break;
                        }
                    }

                    givenHints = givenHints - 1;

                    // Display The word now after given hint
                    wordDisplay(wordGuess);

                } else {
                    cout << "You have 0 hints" << endl;
                }

            } else if(option == 4) {
                // Look at already used characters

                cout << "Your Used Characters: " << endl;

                for (char c : usedChar) {
                    cout << c << endl;
                }

            } else if(option == 5) {
                // Look at already used words
                cout << "Your Used Words: " << endl;

                for (string str : usedWords) {
                    cout << str << endl;
                }
            } else if(option == 6) {
                giveInstructions();
            }

        }

        // Check if game is over, if 1 it is over if 0 loop continues
        if(gameover(guesses, word.length())) {
            cout << "The Word Was " << word << endl;
            break;
        }

    }



    cout << "Game Ended" << endl;
}
