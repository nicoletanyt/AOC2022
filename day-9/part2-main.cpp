#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

bool checkNearby(pair<int, int> hCoords, pair<int, int> tCoords, vector<pair<int, int> > surroundingTCoords) {
    //check the surrounding 9 box radius of T's coords

    for (int i = 0; i < surroundingTCoords.size(); i++) {
        if (hCoords == surroundingTCoords[i]) {
            return true;
        }
    }
    return false;
}

pair<int, int> checkOverlap(pair<int, int> hCoords, pair<int, int> tCoords, vector<pair<int, int> > surroundingTCoords) {
    bool noOverlap = true;

    vector<pair<int, int> > surroundingHCoords;
    surroundingHCoords.push_back(make_pair(hCoords.first - 1, hCoords.second + 1));
    surroundingHCoords.push_back(make_pair(hCoords.first, hCoords.second + 1));
    surroundingHCoords.push_back(make_pair(hCoords.first + 1, hCoords.second + 1));
    surroundingHCoords.push_back(make_pair(hCoords.first - 1, hCoords.second));
    surroundingHCoords.push_back(make_pair(hCoords.first, hCoords.second));
    surroundingHCoords.push_back(make_pair(hCoords.first + 1, hCoords.second));
    surroundingHCoords.push_back(make_pair(hCoords.first - 1, hCoords.second - 1));
    surroundingHCoords.push_back(make_pair(hCoords.first, hCoords.second - 1));
    surroundingHCoords.push_back(make_pair(hCoords.first + 1, hCoords.second - 1));
    //four edges adjacent to the hCoords
    vector<pair<int, int> > hCoordsEdges;
    hCoordsEdges.push_back(make_pair(hCoords.first, hCoords.second + 1));
    hCoordsEdges.push_back(make_pair(hCoords.first, hCoords.second - 1));
    hCoordsEdges.push_back(make_pair(hCoords.first + 1, hCoords.second));
    hCoordsEdges.push_back(make_pair(hCoords.first - 1, hCoords.second));

    vector<pair<int, int> >::iterator it;

    for (int i = 0; i < hCoordsEdges.size(); i++) {
        it = find(surroundingTCoords.begin(), surroundingTCoords.end(), hCoordsEdges[i]);
        if (it != surroundingTCoords.end()) {
            tCoords = hCoordsEdges[i];
            noOverlap = false;
            break;
        }
    }
    if (noOverlap) {
        for (int i = 0; i < surroundingHCoords.size(); i++) {
            it = find(surroundingTCoords.begin(), surroundingTCoords.end(), surroundingHCoords[i]);
            if (it != surroundingTCoords.end()) {
                tCoords = surroundingHCoords[i];
                break;
            }
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
    vector<pair<int, int> > ropeCoords; //arr storing the coords 
    vector<pair<int, int> > surroundingTCoords;

    for (int i = 0; i < 10; i++) {
        ropeCoords.push_back(make_pair(0, 0));
    }

    ifstream dataFile("data.txt");
    while (getline(dataFile, instruction)) {
        int spaceIndex = instruction.find(' ');
        string numSteps = instruction.substr(spaceIndex + 1, instruction.length());
        for (int i = 0; i < stoi(numSteps); i++) {
            hCoords = moveH(hCoords, instruction[0]);
            ropeCoords[0] = hCoords;
            // cout << hCoords.first << ", " << hCoords.second << endl;
            //check if T needs to move
            for (int i = 1; i < 10; i++) {
                surroundingTCoords.clear();
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first - 1, ropeCoords[i].second + 1));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first, ropeCoords[i].second + 1));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first + 1, ropeCoords[i].second + 1));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first - 1, ropeCoords[i].second));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first, ropeCoords[i].second));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first + 1, ropeCoords[i].second));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first - 1, ropeCoords[i].second - 1));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first, ropeCoords[i].second - 1));
                surroundingTCoords.push_back(make_pair(ropeCoords[i].first + 1, ropeCoords[i].second - 1));

                if (checkNearby(ropeCoords[i - 1], ropeCoords[i], surroundingTCoords) == false) {
                    ropeCoords[i] = checkOverlap(ropeCoords[i - 1], ropeCoords[i], surroundingTCoords);
                    // cout << ropeCoords[i].first << ", " << ropeCoords[i].second << endl;
                }
                if (i == 9) { //if this is the last tail, aka 9
                    coordsVisited.push_back(ropeCoords[i]);
                }
            }
        }
        cout << endl;
    }

    sort(coordsVisited.begin(), coordsVisited.end());
    auto last = unique(coordsVisited.begin(), coordsVisited.end());
    coordsVisited.erase(last, coordsVisited.end());

    cout << coordsVisited.size();

    return 0;

};