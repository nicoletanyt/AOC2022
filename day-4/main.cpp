#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int checkForCommon(vector<int> vector1, vector<int> vector2, int totalCommon) {
  vector<int> v(vector1.size() + vector2.size());
  vector<int>::iterator it, st;

  it = set_intersection(vector1.begin(),
                        vector1.end(),
                        vector2.begin(),
                        vector2.end(),
                        v.begin());
  

  for (st = v.begin(); st != it; ++st) {
    // cout << *st << endl;
    totalCommon += 1;
    break;
  }
  return totalCommon;
}

vector<int> splitStringToNum(string part, vector<int> dataRange) {
  int charIndex = part.find("-");
  dataRange.push_back(stoi(part.substr(0, charIndex)));
  dataRange.push_back(stoi(part.substr(charIndex + 1, part.length())));
  return dataRange;
}

int main() {
  ifstream dataFile("data.txt");
  string pair;
  vector<int> dataRange;
  int totalRepeat = 0;
  int totalCommon = 0;

  while (getline(dataFile, pair, '\n')){
    //splits each pair into two substrings
    int commaIndex = pair.find(",");
    string part1, part2;
    part1 = pair.substr(0, commaIndex);
    part2 = pair.substr(commaIndex + 1, pair.length());

    //stores the numbers into the dataRange vector after splitting 
    dataRange = splitStringToNum(part1, dataRange);
    dataRange = splitStringToNum(part2, dataRange);
  }

  // for (int i = 0; i < dataRange.size(); i++){
  //   cout << dataRange[i] << "\n";
  // }

  for (int i = 0; i < dataRange.size(); i+=4) {
    string set1 = "";
    string set2 = "";
    vector<int> num1 = {};
    vector<int> num2 = {};
    for (int j = dataRange[i]; j <= dataRange[i + 1]; j++){
      set1 = set1 + "/" + to_string(j) + "/";
      num1.push_back(j);
    }
    for (int j = dataRange[i + 2]; j <= dataRange[i + 3]; j++){
      set2 = set2 + "/" + to_string(j) + "/";
      num2.push_back(j);
    }
    // check for overlapping strings
    if (set1.find(set2) != string::npos || set2.find(set1) != string::npos) {
      totalRepeat += 1;
    }
    //check for common
    totalCommon = checkForCommon(num1, num2, totalCommon);
  }
  
  cout << totalRepeat << endl;
  cout << totalCommon;
  return 0;
}