#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/*
X/A - Rock
Y/B - Paper
Z/C - Scissors
*/

int main() {
  ifstream dataFile("data.txt");
  vector<string> data;

  // converts the data into a vector
  string text;

  while (getline(dataFile, text, '\n')) {
    data.push_back(text);
  }

  // prints the data
  // if (data.size() != 0) {
  //   for (int i = 0; i < data.size(); i++) {
  //     cout << data[i] << ", ";
  //   }
  // }

  int scorePerRound = 0;
  string a = "A";
  string b = "B";
  string c = "C";
  string x = "X";
  string y = "Y";
  string z = "Z";

  for (int i = 0; i < data.size(); i++) {
    // reads your input and adds score
    if (data[i].find(x) != std::string::npos) {
      scorePerRound = scorePerRound + 1;
    }
    if (data[i].find(y) != std::string::npos) {
      scorePerRound = scorePerRound + 2;
    }
    if (data[i].find(z) != std::string::npos) {
      scorePerRound = scorePerRound + 3;
    }
    // reads you & opponent input and adds score
    if (data[i].find(x) != std::string::npos) {
      // if you input X
      if (data[i].find(a) != std::string::npos) {
        scorePerRound = scorePerRound + 3;
      } else if (data[i].find(c) != std::string::npos) {
        scorePerRound = scorePerRound + 6;
      }
    } else if (data[i].find(y) != std::string::npos) {
      // if you input Y
      if (data[i].find(b) != std::string::npos) {
        scorePerRound = scorePerRound + 3;
      } else if (data[i].find(a) != std::string::npos) {
        scorePerRound = scorePerRound + 6;
      }
    } else if (data[i].find(z) != std::string::npos) {
      // if you input Z
      if (data[i].find(c) != std::string::npos) {
        scorePerRound = scorePerRound + 3;
      } else if (data[i].find(b) != std::string::npos) {
        scorePerRound = scorePerRound + 6;
      }
    }
  }
  cout << scorePerRound;
  return 0;
}