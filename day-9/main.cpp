#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

bool checkNearby(pair<int, int> hCoords, pair<int, int> tCoords, vector<pair<int, int> > surroundingTCoords) {
    //check the surrounding 9 box radius of T's coords
    // int x = tCoords.first;
    // int y = tCoords.second;

    for (int i = 0; i < surroundingTCoords.size(); i++) {
        if (hCoords == surroundingTCoords[i]) {
            return true;
        }
    }

    // if ((hCoords == topLeft) || (hCoords == topMiddle) || (hCoords == topRight) || (hCoords == left) || (hCoords == middle) || (hCoords == right) || (hCoords == bottomLeft) || (hCoords == bottomMiddle) || (hCoords == bottomRight)) {
    //     return true;
    // }
    return false;
}

pair<int, int> checkOverlap(pair<int, int> hCoords, pair<int, int> tCoords, vector<pair<int, int> > surroundingTCoords) {
    //four edges adjacent to the hCoords
    vector<pair<int, int> > surroundingHCoords;
    pair<int, int> top(hCoords.first, hCoords.second + 1);
    pair<int, int> left(hCoords.first - 1, hCoords.second);
    pair<int, int> right(hCoords.first + 1, hCoords.second);
    pair<int, int> bottom(hCoords.first, hCoords.second - 1);
    surroundingHCoords.push_back(top);
    surroundingHCoords.push_back(left);
    surroundingHCoords.push_back(right);
    surroundingHCoords.push_back(bottom);

    vector<pair<int, int> >::iterator it;

    for (int i = 0; i < surroundingHCoords.size(); i++) {
        it = find(surroundingTCoords.begin(), surroundingTCoords.end(), surroundingHCoords[i]);
        if (it != surroundingTCoords.end()) {
            tCoords = surroundingHCoords[i];
            break;
        }
    }
    return tCoords;
}

pair<int, int> moveH(pair<int, int> hCoords, char direction) {
    switch (direction) {
    case 'R':
        hCoords.first++;
        break;
    case 'L':
        hCoords.first--;
        break;
    case 'U':
        hCoords.second++;
        break;
    case 'D':
        hCoords.second--;
        break;
    }
    return hCoords;
}

int main() {

    string instruction;
    vector<pair<int, int> > coordsVisited;
    vector<pair<int, int> >::iterator it;
    pair<int, int> hCoords(0, 0);
    pair<int, int> tCoords(0, 0);
    vector<pair<int, int> > surroundingTCoords;

    ifstream dataFile("data.txt");
    while (getline(dataFile, instruction)) {
        int spaceIndex = instruction.find(' ');
        string numSteps = instruction.substr(spaceIndex + 1, instruction.length());
        for (int i = 0; i < stoi(numSteps); i++) {
            hCoords = moveH(hCoords, instruction[0]);
            // cout << hCoords.first << ", " << hCoords.second << endl;
            //check if T needs to move

            surroundingTCoords.clear();
            surroundingTCoords.push_back(make_pair(tCoords.first - 1, tCoords.second + 1));
            surroundingTCoords.push_back(make_pair(tCoords.first, tCoords.second + 1));
            surroundingTCoords.push_back(make_pair(tCoords.first + 1, tCoords.second + 1));
            surroundingTCoords.push_back(make_pair(tCoords.first - 1, tCoords.second));
            surroundingTCoords.push_back(make_pair(tCoords.first, tCoords.second));
            surroundingTCoords.push_back(make_pair(tCoords.first + 1, tCoords.second));
            surroundingTCoords.push_back(make_pair(tCoords.first - 1, tCoords.second - 1));
            surroundingTCoords.push_back(make_pair(tCoords.first, tCoords.second - 1));
            surroundingTCoords.push_back(make_pair(tCoords.first + 1, tCoords.second - 1));

            if (checkNearby(hCoords, tCoords, surroundingTCoords) == false) {
                tCoords = checkOverlap(hCoords, tCoords, surroundingTCoords);
                // cout << tCoords.first << ", " << tCoords.second << endl;
                coordsVisited.push_back(tCoords);
            }
        }
    }

    sort(coordsVisited.begin(), coordsVisited.end());
    auto last = unique(coordsVisited.begin(), coordsVisited.end());
    coordsVisited.erase(last, coordsVisited.end());

    cout << coordsVisited.size() + 1;

    return 0;

};