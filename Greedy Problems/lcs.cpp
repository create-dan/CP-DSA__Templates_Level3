#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

bool isPalindrome(string &s)
{
    string rev = s;
    reverse(s.begin(), s.end());

    return rev == s;
}

int countDigit(int n)
{
    return floor(log10(n) + 1);
}

int kadaneAlgo(int n, int a[], int num)
{
    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            curr++;
            ans = max(curr, ans);
        }
        else
        {
            curr = 0;
        }
    }

    return ans;
}

int xorOfNum(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans ^= i;
    }

    return ans;
}

int lcsAlgo(string s1, string s2, int m, int n)
{
    int mat[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    mat[i][j] = mat[i - 1][j - 1] + 1;
                }
                else
                {
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
                }
            }
        }
    }

    return mat[m][n];
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int m = s1.length();
        int n = s2.length();

        int ans = lcsAlgo(s1, s2, m, n);
        cout << ans << endl;
    }

    return 0;
}
