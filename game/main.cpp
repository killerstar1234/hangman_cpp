#include <iostream>
#include <string>

#include "getRandomWord.h"
#include "game.h"

using namespace std;
int main() {

    // Get random Word
    string secretWord = getRandomWord();

    // Change the word to lowercase
    for(auto& c : secretWord) {
        c = tolower(c);
    }

    // Run the game, get input deal with input ect...
    game(secretWord);

    return 0;
}