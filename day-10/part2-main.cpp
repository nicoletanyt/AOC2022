#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

void draw(int x, int cycleNum) {
    //run everytime cycleNum++
    int line = floor(cycleNum / 40) + 1;
    int xPosition = x + ((line - 1) * 40);

    if (cycleNum % 40 == 0) {
        cout << endl;
    }
    if (cycleNum >= xPosition - 1 && cycleNum <= xPosition + 1) {
        cout << "#";
    }
    // if (cycleNum == xPosition - 1 || cycleNum == xPosition || cycleNum == xPosition + 1) {
    //     cout << "#";
    // }
    else {
        cout << ".";
    }
}

int main() {
    ifstream dataFile("data.txt");
    string line;
    int cycleNum = 0, x = 1, numAdd = 0;

    while (getline(dataFile, line)) {
        if (cycleNum < 240) {
            if (line[0] == 'n') {
                draw(x, cycleNum);
                cycleNum++;
            }
            else {
                numAdd = stoi(line.substr(line.find(' ')));
                for (int i = 0; i < 2; i++) {
                    draw(x, cycleNum);
                    cycleNum++;
                }
                x += numAdd;
            }
        }
    }

    cout << endl;
    return 0;
}