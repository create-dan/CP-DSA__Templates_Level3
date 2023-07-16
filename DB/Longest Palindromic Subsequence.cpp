// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LCS(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();

        int arr[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    arr[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                }
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }

        return arr[n][m];
    }

    int longestPalinSubseq(string s)
    {

        string s1 = s;
        reverse(s1.begin(), s1.end());

        return LCS(s, s1);
    }
};