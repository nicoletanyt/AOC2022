#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;

class Graph {
    map<pair<int, int>, list<pair<int, int> > > l; //pair: index, value

public:
    void addEdge(pair<int, int> curr, pair<int, int> nbr) {
        l[curr].push_back(nbr);
    }
    int bfs(int start, int end, vector<int> dataGrid) {
        //only store the index
        map<int, bool> visited;
        queue<pair<int, int> > q; //steps, current index 

        q.push(make_pair(0, start));
        visited[start] = true;

        while (!q.empty()) {
            int nodeIndex = q.front().second;
            int stepCount = q.front().first;
            q.pop();

            for (pair<int, int> nbr : l[make_pair(nodeIndex, dataGrid[nodeIndex])]) { //index: value
                if (!visited[nbr.first] && nbr.second <= dataGrid[nodeIndex] + 1) { //if neighbour is not visited && the nbr does not exceed + 1 of node
                    // cout << nodeIndex << "\t" << nbr.first << ": " << nbr.second << " - " << stepCount << endl;

                    q.push(make_pair(stepCount + 1, nbr.first));
                    visited[nbr.first] = true;

                    if (nbr.first == end) {
                        // cout << nbr.first << endl;
                        return stepCount + 1;
                    }
                }
            }
        }
        return -1;
    }
    void printList(int rowLength, int rowCount) {
        for (const auto& [key, value] : myMap) {
            cout << "Key: (" << key.first << ", " << key.second << ")" << endl;
            cout << "Value: [";
            for (const auto& [first, second] : value) {
                cout << "(" << first << ", " << second << ") ";
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    ifstream dataFile("data.txt");
    string row;
    int rowLength = 0, rowCount = 0;
    Graph g;
    vector<vector<int> > data;
    vector<int> dataGrid; //data but with 1 pos
    int end;
    vector<int> start, stepsPossible;

    // reads data
    while (getline(dataFile, row)) {
        rowLength = row.length();
        vector<int> rowInt;
        for (int i = 0; i < rowLength; i++) {
            if (row[i] == 'S' || row[i] == 'a') {
                row[i] = 'a';
                start.push_back(rowCount * rowLength + i);
            }
            if (row[i] == 'E') {
                row[i] = 'z';
                end = rowCount * rowLength + i;
            }
            rowInt.push_back(row[i] - 96);
        }
        rowCount++;
        data.push_back(rowInt);
    }

    for (int j = 0; j < data.size(); j++) {
        for (int i = 0; i < data[j].size(); i++) {
            dataGrid.push_back(data[j][i]);
            // cout << data[j][i] << " ";
            int index;
            index = rowLength * j + i;
            // cout << index << endl;
            if (i - 1 >= 0)
                g.addEdge(make_pair(index, data[j][i]), make_pair((rowLength * j + i - 1), data[j][i - 1]));
            if (j - 1 >= 0)
                g.addEdge(make_pair(index, data[j][i]), make_pair((rowLength * (j - 1) + i), data[j - 1][i]));
            if (i + 1 < rowLength)
                g.addEdge(make_pair(index, data[j][i]), make_pair((rowLength * j + i + 1), data[j][i + 1]));
            if (j + 1 < rowCount)
                g.addEdge(make_pair(index, data[j][i]), make_pair((rowLength * (j + 1) + i), data[j + 1][i]));
        }
    }

    for (int i = 0; i < start.size(); i++) {
        int step = g.bfs(start[i], end, dataGrid);
        if (step >= 0) {
            stepsPossible.push_back(step);
        }
    }
    // g.printList(rowLength, rowCount);

    sort(stepsPossible.begin(), stepsPossible.end());
    cout << stepsPossible.front();

    return 0;
}