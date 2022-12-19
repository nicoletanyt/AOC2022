#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

bool checkVisible(map<pair<int, int>, int> dataTrees, int x, int y, int maxLength) {
    vector<int> surrounding;
    int cell;
    //top
    for (int i = y; i >= 0; i--) {
        cell = dataTrees[make_pair(x, i)];
        surrounding.push_back(cell);
        if (surrounding.size() > 1) {
            if (surrounding[0] <= surrounding.back()) {
                break;
            }
        }
        if (i == 0) {
            return true; //return value cuz it alr exists
        }
    }
    surrounding.clear();
    //bottom
    for (int i = y; i < maxLength; i++) {
        cell = dataTrees[make_pair(x, i)];
        surrounding.push_back(cell);
        if (surrounding.size() > 1) {
            if (surrounding[0] <= surrounding.back()) {
                break;
            }
        }
        if (i == maxLength - 1) {
            return true; //return value cuz it alr exists
        }
    }
    surrounding.clear();

    //left
    for (int i = x; i >= 0; i--) {
        cell = dataTrees[make_pair(i, y)];
        surrounding.push_back(cell);
        if (surrounding.size() > 1) {
            if (surrounding[0] <= surrounding.back()) {
                break;
            }
        }
        if (i == 0) {
            return true; //return value cuz it alr exists
        }
    }
    surrounding.clear();

    //right
    for (int i = x; i < maxLength; i++) {
        cell = dataTrees[make_pair(i, y)];
        surrounding.push_back(cell);
        if (surrounding.size() > 1) {
            if (surrounding[0] <= surrounding.back()) {
                break;
            }
        }
        if (i == maxLength - 1) {
            return true; //return value cuz it alr exists
        }
    }
    return false;
}

int main() {
    ifstream dataFile("data.txt");
    string row;
    int rowCount = 0;
    map<pair<int, int>, int>  dataTrees;
    while (getline(dataFile, row)) {
        for (int i = 0; i < row.length(); i++) {
            dataTrees[make_pair(i, rowCount)] = row[i] - 48;
        }
        rowCount++;
    }
    long numVisible = 0;
    numVisible = (rowCount - 1) * 4; //edges    

    map<pair<int, int>, int>::iterator itr;
    for (itr = dataTrees.begin(); itr != dataTrees.end(); ++itr) {
        int x = itr->first.first;
        int y = itr->first.second;
        if (x != 0 && x != (rowCount - 1) && y != 0 && y != (rowCount - 1)) {
            //interior trees
            if (checkVisible(dataTrees, x, y, rowCount)) {
                numVisible++;
            }
        }
    }
    cout << numVisible;

    return 0;
}