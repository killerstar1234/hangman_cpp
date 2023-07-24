#include <iostream>

using namespace std;
int gameover(int guesses, int wordLength) {
    if(guesses == wordLength) {
        cout << "You used all your Guesses!" << endl;
        return 1;
    } else {
        return 0;
    }
}