#include <bits/stdc++.h>
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

  sort(totalNumForEach.begin(), totalNumForEach.end());
  vector<int> topThree;
  for (int i = totalNumForEach.size() - 1; i > totalNumForEach.size() - 4; i--) {
    topThree.push_back(totalNumForEach[i]);
  }

  int sum = 0;
  for (int i = 0; i < topThree.size(); i++) {
    sum = sum + topThree[i];
    // cout << "\n" << topThree[i];
  }

  cout << sum;

  return 0;
}
