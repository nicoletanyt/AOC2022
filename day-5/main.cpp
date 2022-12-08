#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<char> reverseCrate(vector<char> v) {
    vector<char> reversedVec;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (isalpha(v[i]) != 0) {
            reversedVec.push_back(v[i]);
        }
    }
    return reversedVec;
}

vector<vector<char> > moveCrate(int numToMove, vector<vector<char> > totalData, int colFromIndex, int colToIndex) {
    char toAdd;
    //for every crate to move
    for (int i = 0; i < numToMove; i++) {
        //removes the crate on the top 
        toAdd = totalData[colFromIndex].back();
        totalData[colFromIndex].pop_back();
        totalData[colToIndex].push_back(toAdd);
    }
    return totalData;
}

string getTop(vector<vector<char> > totalData) {
    string topCrates = "";
    for (int i = 0; i < totalData.size(); i++) {
        topCrates += totalData[i].back();
    }
    return topCrates;
}

int main()
{
    ifstream dataFile("testData.txt"); // read file
    string text;
    vector<vector<char> > totalData;
    vector<string> instructions, outputData;
    vector<char> col1, col2, col3, col4, col5, col6, col7, col8, col9;

    // splits data file into two vectors: 1 for instructions, 1 for crates (output data)
    while (getline(dataFile, text))
    {
        if (text.find("move") != string::npos)
        {
            instructions.push_back(text);
        }
        else
        {
            outputData.push_back(text);
        }
    }

    for (int i = 0; i < outputData.size() - 2; i++)
    {
        for (int j = 0; j < outputData[i].length(); j++)
        {
            // loops through each character in the output data vector
            if (j % 4 == 2) {
                // gets the index of the crate value
                switch (j / 4) {
                    //gets the columns of the crate
                case 0:
                    col1.push_back(outputData[i][j - 1]);
                    break;
                case 1:
                    col2.push_back(outputData[i][j - 1]);
                    break;
                case 2:
                    col3.push_back(outputData[i][j - 1]);
                    break;
                case 3:
                    col4.push_back(outputData[i][j - 1]);
                    break;
                case 4:
                    col5.push_back(outputData[i][j - 1]);
                    break;
                case 5:
                    col6.push_back(outputData[i][j - 1]);
                    break;
                case 6:
                    col7.push_back(outputData[i][j - 1]);
                    break;
                case 7:
                    col8.push_back(outputData[i][j - 1]);
                    break;
                case 8:
                    col9.push_back(outputData[i][j - 1]);
                    break;
                default:
                    // cout << "Not enough row vectors";
                    cout << j / 4;
                    break;
                }
            }
        }
    }

    col1 = reverseCrate(col1);
    col2 = reverseCrate(col2);
    col3 = reverseCrate(col3);
    col4 = reverseCrate(col4);
    col5 = reverseCrate(col5);
    col6 = reverseCrate(col6);
    col7 = reverseCrate(col7);
    col8 = reverseCrate(col8);
    col9 = reverseCrate(col9);

    totalData.push_back(col1);
    totalData.push_back(col2);
    totalData.push_back(col3);
    totalData.push_back(col4);
    totalData.push_back(col5);
    totalData.push_back(col6);
    totalData.push_back(col7);
    totalData.push_back(col8);
    totalData.push_back(col9);

    for (int i = 0; i < instructions.size(); i++)
    {
        vector<char> instructionsIndex;
        for (int j = 0; j < instructions[i].length(); j++) {
            if (isdigit(instructions[i][j]) != 0) { //is an alphabet 
                instructionsIndex.push_back(instructions[i][j]);
            }
        }
        string numToMove;
        for (int k = 0; k < instructionsIndex.size() - 2; k++) {
            numToMove += instructionsIndex[k];
        }
        int colFromIndex, colToIndex;
        colFromIndex = int(instructionsIndex[instructionsIndex.size() - 2] - 49);
        colToIndex = int(instructionsIndex.back()) - 49;

        totalData = moveCrate(stoi(numToMove), totalData, colFromIndex, colToIndex);
    }

    cout << getTop(totalData);

    return 0;
}