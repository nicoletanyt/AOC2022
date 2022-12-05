#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

int convertNum(string letter) {
  ifstream alphabetFile("alphabet.txt");
  vector<string> alphabet;
  string text;

  while (getline(alphabetFile, text, ',')) {
    alphabet.push_back(text);
  }
  //creates a map with the keys as letters & elements as priority level
  map<string, int> intChar;
  for (int i = 0; i < alphabet.size(); i ++){
    intChar.insert({alphabet[i], i + 1});
  }
  // prints map
  // for (auto itr = intChar.begin(); itr != intChar.end(); ++itr) {
  //   cout << itr->first << '\t' << itr->second << '\n';
  // }

  // cout << letter << ": " << intChar[letter] << endl;
  return intChar[letter];
}

int main() {
  ifstream dataFile("data.txt");
  vector<string> data;
  string text;
  // converts the data into a vector
  while (getline(dataFile, text, '\n')) {
    data.push_back(text);
  }

  string group1, group2, group3;
  vector<char> commonLettersTotal;
  vector<char>::iterator it; // for preventing duplicates
  int totalSum = 0;

  for (int i = 0; i < data.size(); i+=3) {
    //sets string values
    group1 = data[i];
    group2 = data[i + 1];
    group3 = data[i + 2];
    // finds & saves common letter in a vector
    vector<char> commonLetter = {};
    for (int k = 0; k < group2.length(); k++) {
      if (group1.find(group2[k]) != string::npos) {
        if (group3.find(group2[k]) != string::npos) {
          // prevents duplicates of common letters
          it = find(commonLetter.begin(), commonLetter.end(), group2[k]);
          if (it != commonLetter.end()) {
            break;
          } else {
            // saves common letter if it doesn't exist already
            commonLetter.push_back(group2[k]);
          }
        }
      }
    }
    // adds common letter to vector with total common letters
    for (int p = 0; p < commonLetter.size(); p++) {
      commonLettersTotal.push_back(commonLetter[p]);
    }
  }

  for (int i = 0; i < commonLettersTotal.size(); i++) {
    // cout << commonLettersTotal[i] << "\n";
    totalSum = totalSum + convertNum(string(1, commonLettersTotal[i]));
  }
  cout << totalSum;
  return 0;
}