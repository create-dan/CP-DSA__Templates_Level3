// https: // leetcode.com/problems/number-of-music-playlists/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numMusicPlaylists(int N, int L, int K)
    {
        const int mod = 1000000007;

        vector<vector<long long>> dp(1 + N, vector<long long>(1 + L, 0LL));
        dp[1][1] = 1;
        for (int i = 2; i <= N; ++i)
        {
            dp[i][i] = (dp[i - 1][i - 1] * i) % mod;
        }
        for (int n = 1; n <= N; ++n)
        {
            for (int l = n + 1; l <= L; ++l)
            {
                dp[n][l] = ((dp[n][l - 1] * ((n - K) > 0 ? (n - K) : 0)) % mod + (dp[n - 1][l - 1] * n) % mod) % mod;
            }
        }

        return dp[N][L];
    }
};