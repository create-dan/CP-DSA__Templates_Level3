// 2
//  7 3 2 2 -- > 3
//  8 1 4 4 -- > 8

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// Normal brute force using recursion
int solve1(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
        return INT_MIN;

    int a = solve1(n - x, x, y, z) + 1;
    int b = solve1(n - y, x, y, z) + 1;
    int c = solve1(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

// Memoization

int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];

    int a = solveMem(n - x, x, y, z, dp) + 1;
    int b = solveMem(n - y, x, y, z, dp) + 1;
    int c = solveMem(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

// Tabulation

int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);

        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{

    int ans = solve1(n, x, y, z);
    if (ans < 0)
        return 0;
    else
        return ans;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        // solve1
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        cout << cutSegments(n, x, y, z) << endl;

        // solveMem
        vector<int> dp(n + 1, -1);

        // Tabulation
    }

    return 0;
}