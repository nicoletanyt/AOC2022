#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ifstream dataFile("data.txt");
  vector<string> data;
  string text;
  // converts the data into a vector
  while (getline(dataFile, text, '\n')) {
    data.push_back(text);
  }

  // prints the data
  // if (data.size() != 0) {
  //   for (int i = 0; i < data.size(); i++) {
  //     // cout << data[i] << ",";
  //   }
  // }
  
  vector<int> totalNumForEach = {0};
  if (data.size() > 0) {
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == "") {
        // creates a new element in the vector
        totalNumForEach.push_back(0);
      } else {
        totalNumForEach[totalNumForEach.size() - 1] =
            totalNumForEach[totalNumForEach.size() - 1] + stoi(data[i]);
      }
    }
  }
  
  int largestNum;

  for (int i = 0; i < totalNumForEach.size(); i++) {
    // loops through all the values
    if (totalNumForEach[i] > largestNum) {
      largestNum = totalNumForEach[i];
    }
  }

  cout << largestNum;

  return 0;
}