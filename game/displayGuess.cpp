#include <string>
#include <iostream>
#include <vector>

using namespace std;
void wordDisplay(const vector<char>& word) {

    cout << endl;
    cout << "Current Word - ";

    for(char c : word) {
        if(c == '\0') {
            cout << "x";
        } else {
            cout << c;
        }
    }

    cout << endl;
    cout << endl;

}