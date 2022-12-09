#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream dataFile("testData.txt"); // read file
    string data;
    bool marker = false;
    int charDetectedIndex;

    getline(dataFile, data);
    for (int i = 0; i < data.length(); i++) {
        string currentLetter;
        currentLetter += data[i];
        for (int k = i + 1; k < i + 4; k++) { //loop through next 4 characters
            if (!(currentLetter.find(data[k]) != string::npos)) {
                marker = true;
                currentLetter += data[k];
            }
            else {
                marker = false;
                break;
            }
        }
        if (marker) {
            charDetectedIndex = i + 4;
            break;
        }
        currentLetter = "";
    }

    cout << charDetectedIndex;

    return 0;
}