#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>

using namespace std;
string getRandomWord() {

    // Get all the words and put them in a vector

    ifstream file("words.txt");

    vector <vector<string>> mainVector;

    string line;
    while (getline(file, line)) {
        vector<string> tempVec;
        tempVec.push_back(line);
        mainVector.push_back(tempVec);
    }

    // Pick a random word from the vector

    mt19937 myRng; //Random Number Generator
    random_device dev; //Used as seed
    myRng.seed(dev()); //Seeding Generator

    uniform_int_distribution<mt19937::result_type> genX(0, mainVector.size());
    int num = genX(myRng); //Generates random number in range RANGE_START to RANGE_END

    return mainVector[num][0];

}