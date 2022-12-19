#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long signalStrength(int cycleNum, int x) {
    if ((cycleNum - 20) % 40 == 0) {
        return x * cycleNum;
    }
    return 0;
}

int main() {
    ifstream dataFile("data.txt");
    string line;
    int cycleNum = 0, x = 1, numAdd = 0;
    long sum = 0;

    while (getline(dataFile, line)) {
        if (cycleNum < 220) {
            if (line[0] == 'n') {
                cycleNum++;
                sum += signalStrength(cycleNum, x);
            }
            else {
                numAdd = stoi(line.substr(line.find(' ')));
                for (int i = 0; i < 2; i++) {
                    cycleNum++;
                    sum += signalStrength(cycleNum, x);
                }
                x += numAdd;
            }
        }
    }
    cout << sum << endl;

    return 0;
}