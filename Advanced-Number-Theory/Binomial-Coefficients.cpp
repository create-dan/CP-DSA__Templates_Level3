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

int binomial1(int a, int b, int m)
{
    if (b == 0 || b == a)
    {
        return 1;
    }

    else
    {
        return binomial1(a - 1, b - 1, m) + binomial1(a - 1, b, m);
    }
}

int binomial2(int a, int b, int m)
{
    if (a < b)
        return 0;
    if ((a - b) < b)
        b = a - b;

    int dp[b + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= a; i++)
    {
        for (int j = min(b, i); j > 0; j--)
        {
            dp[j] = (dp[j] + dp[j - 1]) % m;
        }
    }
    // for (int i = 0; i <= b; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    return dp[b];
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int m = 1e9 + 7;
        // int ans = binomial1(a, b, m);
        int ans = binomial2(a, b, m);
        cout << ans << endl;
    }

    return 0;
}