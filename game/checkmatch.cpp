#include <iostream>
#include <string>
#include <vector>


using namespace std;
int match(string wordGuess, string word) {

    if(wordGuess == word) {
        return 1;
    } else {
        return 0;
    }

}