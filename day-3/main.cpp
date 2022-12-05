// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <vector>
// #include <iterator>
// #include <map>
// using namespace std;

// int convertNum(string letter) {
//   ifstream alphabetFile("alphabet.txt");
//   vector<string> alphabet;
//   string text;

//   while (getline(alphabetFile, text, ',')) {
//     alphabet.push_back(text);
//   }
//   //creates a map with the keys as letters & elements as priority level
//   map<string, int> intChar;
//   for (int i = 0; i < alphabet.size(); i ++){
//     intChar.insert({alphabet[i], i + 1});
//   }
//   // prints map
//   // for (auto itr = intChar.begin(); itr != intChar.end(); ++itr) {
//   //   cout << itr->first << '\t' << itr->second << '\n';
//   // }

//   // cout << letter << ": " << intChar[letter] << endl;
//   return intChar[letter];
// }

// int main() {
//   ifstream dataFile("testData.txt");
//   vector<string> data;
//   string text;
//   // converts the data into a vector
//   while (getline(dataFile, text, '\n')) {
//     data.push_back(text);
//   }

//   string comp1, comp2;
//   vector<char> commonLettersTotal;
//   vector<char>::iterator it; // for preventing duplicates
//   int totalSum = 0;

//   for (int i = 0; i < data.size(); i++) {
//     // cout << data[i] << ", ";
//     comp1 = "";
//     comp2 = "";

//     // splits the string
//     for (int j = 0; j < data[i].length(); j++) {
//       if (j < data[i].length() / 2) {
//         comp1 += data[i][j];
//       } else {
//         comp2 += data[i][j];
//       }
//     }

//     // finds & saves common letter in a vector
//     vector<char> commonLetter = {};
//     for (int k = 0; k < comp2.length(); k++) {
//       if (comp1.find(comp2[k]) != string::npos) {
//         // prevents duplicates of common letters
//         it = find(commonLetter.begin(), commonLetter.end(), comp2[k]);
//         if (it != commonLetter.end()) {
//           break;
//         } else {
//           // saves common letter if it doesn't exist already
//           commonLetter.push_back(comp2[k]);
//         }
//       }
//     }
//     // adds common letter to vector with total common letters
//     for (int p = 0; p < commonLetter.size(); p++) {
//       commonLettersTotal.push_back(commonLetter[p]);
//     }
//   }

//   for (int i = 0; i < commonLettersTotal.size(); i++) {
//     // cout << commonLettersTotal[i] << "\n";
//     totalSum = totalSum + convertNum(string(1, commonLettersTotal[i]));
//   }
//   cout << totalSum;
//   return 0;
// }