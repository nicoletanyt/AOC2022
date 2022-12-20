#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Monkey {
public:
    int num, testCondition, ifTrue, ifFalse;
    vector<int> startingItems;
    string operation;

    int getOperation() {
        if (operation.length() == 3) {
            return operation[2] - 48;
        }
        else if (operation.length() == 4) {
            string opNum = operation.substr(2, operation.length());
            return stoi(opNum);
        }
        else if (operation.length() == 5) {
            return 0; //it will multiply itself
        }
        return -1;
    }
};

int main() {
    ifstream dataFile("data.txt");
    string line, item;
    vector<Monkey> monkeys;
    vector<int> numInspected;
    int lineNum = 0;
    //read value & create objects of Monkey
    while (getline(dataFile, line)) {
        lineNum++;
        if (lineNum % 7 == 1) {
            Monkey newMonkey;
            newMonkey.num = lineNum / 7;
            monkeys.push_back(newMonkey);
        }
        else  if (lineNum % 7 == 2) {
            string items = line.substr(18, line.length());
            stringstream startItemStr(items);
            while (getline(startItemStr, item, ' ')) {
                monkeys[lineNum / 7].startingItems.push_back(stoi(item.erase(2)));
            }
        }
        else if (lineNum % 7 == 3) {
            monkeys[lineNum / 7].operation = line.substr(23, line.length());
        }
        else if (lineNum % 7 == 4) {
            monkeys[lineNum / 7].testCondition = stoi(line.substr(21, line.length()));
        }
        else if (lineNum % 7 == 5) {
            monkeys[lineNum / 7].ifTrue = stoi(line.substr(29, line.length()));
        }
        else if (lineNum % 7 == 6) {
            monkeys[lineNum / 7].ifFalse = stoi(line.substr(30, line.length()));
        }
    }

    for (int i = 0; i < monkeys.size(); i++) {
        numInspected.push_back(0);
    }

    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < monkeys.size(); i++) {
            Monkey currentMonkey = monkeys[i];
            int worryLevel;
            while (currentMonkey.startingItems.size() > 0) {
                if (currentMonkey.operation[0] == '+') {
                    if (currentMonkey.getOperation() == 0) {
                        worryLevel = currentMonkey.startingItems[0] + currentMonkey.startingItems[0];
                    }
                    else {
                        worryLevel = currentMonkey.startingItems[0] + currentMonkey.getOperation();
                    }
                }
                else if (currentMonkey.operation[0] == '*') {
                    if (currentMonkey.getOperation() == 0) {
                        worryLevel = currentMonkey.startingItems[0] * currentMonkey.startingItems[0];
                    }
                    else {
                        worryLevel = currentMonkey.startingItems[0] * currentMonkey.getOperation();
                    }
                }
                worryLevel /= 3;
                if (worryLevel % currentMonkey.testCondition == 0) {
                    //if divisble
                    monkeys[currentMonkey.ifTrue].startingItems.push_back(worryLevel);
                }
                else {
                    //not divisible
                    monkeys[currentMonkey.ifFalse].startingItems.push_back(worryLevel);
                }
                numInspected[i] += 1;
                currentMonkey.startingItems.erase(currentMonkey.startingItems.begin());
            }
            monkeys[i] = currentMonkey;
        }
    }
    sort(numInspected.begin(), numInspected.end());
    cout << numInspected[numInspected.size() - 1] * numInspected[numInspected.size() - 2];
    return 0;
}