#include <bits/stdc++.h>
using namespace std;

// Sample Input 1:
// 2
// 5
// 5 3 6 7 9
// 5
// 5 8 9 13 14
// Sample Output 1:
// 4
// 6
int avoidTraps(vector<int> &v, int n)
{

    int mx = 0;

    // cout<<"mx is "<<mx<<endl;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > mx)
        {
            mx = v[i];
        }
    }

    vector<bool> freq(mx, false);

    for (int i = 0; i < n; i++)
    {
        freq[v[i]] = true;
    }

    for (int i = 1; i <= mx; i++)
    {
        bool flag = false;

        for (int j = i; j <= mx; j += i)
        {
            if (freq[j] == true)
            {
                flag = true;
            }
        }

        if (!flag)
            return i;
    }

    return mx + 1;
}