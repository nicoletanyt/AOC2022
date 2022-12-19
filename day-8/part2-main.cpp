#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

long countVisible(map<pair<int, int>, int> dataTrees, int x, int y, int maxLength) {
    vector<int> surrounding;
    int cell;
    long numVisible = 1;
    //top
    for (int i = y; i >= 0; i--) {
        cell = dataTrees[make_pair(x, i)];
        surrounding.push_back(cell);
        if (surrounding.size() > 1) {
            if (surrounding[0] <= surrounding.back()) {
                break;
            }
        }
    }
    numVisible *= (surrounding.size() - 1);
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
    }
    numVisible *= (surrounding.size() - 1);
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
    }
    numVisible *= (surrounding.size() - 1);
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
    }
    numVisible *= (surrounding.size() - 1);

    return numVisible;
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
    vector<long> visibleTotal;

    map<pair<int, int>, int>::iterator itr;
    for (itr = dataTrees.begin(); itr != dataTrees.end(); ++itr) {
        int x = itr->first.first;
        int y = itr->first.second;
        if (x != 0 && x != (rowCount - 1) && y != 0 && y != (rowCount - 1)) {
            //interior trees
            // cout << countVisible(dataTrees, x, y, rowCount) << endl;
            visibleTotal.push_back(countVisible(dataTrees, x, y, rowCount));
        }
    }

    sort(visibleTotal.begin(), visibleTotal.end());
    cout << visibleTotal.back();

    return 0;
}