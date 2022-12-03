#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int rock(int scorePerRound) {
  scorePerRound = scorePerRound + 1;
  return scorePerRound;
}
int paper(int scorePerRound) {
  scorePerRound = scorePerRound + 2;
  return scorePerRound;
}
int scissors(int scorePerRound) {
  scorePerRound = scorePerRound + 3;
  return scorePerRound;
}
int draw(int scorePerRound){
  scorePerRound = scorePerRound + 3;
  return scorePerRound;
}
int win(int scorePerRound){
  scorePerRound = scorePerRound + 6;
  return scorePerRound;
}

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

  /*
    A - Rock; X - Lose
    B - Paper; Y - Draw
    C - Scissors; Z - Win
  */
  
  for (int i = 0; i < data.size(); i++) {
    // reads your opponent's input and adds score
    if (data[i].find("A") != std::string::npos) {
      if (data[i].find("Y") != std::string::npos) {
        scorePerRound = draw(scorePerRound);
        scorePerRound = rock(scorePerRound);
      } else if (data[i].find("Z") != std::string::npos) {
        scorePerRound = win(scorePerRound);
        scorePerRound = paper(scorePerRound);
      }
      else if (data[i].find("X") != std::string::npos){
        scorePerRound = scissors(scorePerRound);
      }
    } else if (data[i].find("B") != std::string::npos) {
      if (data[i].find("Y") != std::string::npos) {
        scorePerRound = draw(scorePerRound);
        scorePerRound = paper(scorePerRound);
      } else if (data[i].find("Z") != std::string::npos) {
        scorePerRound = win(scorePerRound);
        scorePerRound = scissors(scorePerRound);
      } else if (data[i].find("X") != std::string::npos){
        scorePerRound = rock(scorePerRound);
      }
    } else if (data[i].find("C") != std::string::npos) {
      if (data[i].find("Y") != std::string::npos) {
        scorePerRound = draw(scorePerRound);
        scorePerRound = scissors(scorePerRound);
      } else if (data[i].find("Z") != std::string::npos) {
        scorePerRound = win(scorePerRound);
        scorePerRound = rock(scorePerRound);
      }
      else if (data[i].find("X") != std::string::npos){
        scorePerRound = paper(scorePerRound);
      }
    }
    // cout << "\n" << i << ": " << scorePerRound;
  }
  cout << scorePerRound;
  return 0;
}
