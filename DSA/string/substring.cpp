#include<iostream>
using namespace std;

bool isSubstring(string a, string b)
{

    if (a.find(b) != string::npos)
        return true;
    return false;
}

int main()
{
    
}