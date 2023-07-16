#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string str = "aabb";
    int palCount = 0; // It keeps count of the palindrome
    for (int i = 0; i < str.size(); i++)
    {                                   // Outer loop that is the start point of the substring
        unordered_map<char, int> myMap; // To keep count of the characters
        int oddCountChar = 0;           // Keep count of the characters which have the odd frequency
        for (int j = i; j < str.size(); j++)
        {
            if (j == i)
            { // Fo the initial substring i.e. when j==i no of characters with odd freq must be initialized to 1
                myMap[str[j]] = 1;
                oddCountChar = 1;
            }
            else
            {
                myMap[str[j]]++;
                if (myMap[str[j]] % 2 == 0) // If the count of a character has become even that means it was odd before
                    oddCountChar--;
                else
                    oddCountChar++; // If the count of a character has become odd that means it was even before
            }
            if (oddCountChar == 0) // j-i+1 i.e. the length of the substring,if even then no charcaters should have odd frequency
                palCount++;
            else if (oddCountChar == 1) // j-i+1 i.e. the length of the substring,if odd then no charcaters should have even frequency
                palCount++;
        }
    }
    cout << palCount << endl;
    return 0;
}