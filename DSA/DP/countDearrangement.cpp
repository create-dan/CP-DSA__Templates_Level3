#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod 1000000007

// Normal Brute Force

long long int countDerangements(int n)
{
    // Write your code here.
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long long int ans = (((n - 1) % mod) * (countDerangements(n - 1) % mod + countDerangements(n - 2) % mod)) % mod;
    return ans;
}

// REcursion + Memo
long long int solveMem(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (((n - 1) % mod) * (solveMem(n - 1, dp) % mod + solveMem(n - 2, dp) % mod)) % mod;
    return dp[n];
}

// Tabulation
long long int solveTab(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % mod;
        long long int second = dp[i - 2] % mod;
        long long int sum = (first + second) % mod;

        long long int ans = ((i - 1) * sum) % mod;
        dp[i] = ans;
    }

    return dp[n];
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // solve1

        // solveMem
        vector<long long int> dp(n + 1, -1);

        // Tabulation
    }

    return 0;
}