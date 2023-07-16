#include <bits/stdc++.h>
using namespace std;

void helper(string inputFile, string outputFile)
{
    ifstream file(inputFile);

    ofstream file(outputFile);

    if (!file.is_open())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    unordered_map<string, int> mp;
    string word;

    while (file >> word)
    {
        mp[word]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    file.close();
}

int main()
{
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    helper(inputFile, outputFile);
    return 0;
}