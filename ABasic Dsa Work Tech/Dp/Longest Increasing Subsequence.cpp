#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int helper(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }

        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        int notTake = helper(ind + 1, prevInd, n, arr, dp);

        int take = 0;
        if (prevInd == -1 || arr[ind] > arr[prevInd])
        {
            take = 1 + helper(ind + 1, ind, n, arr, dp);
        }

        return dp[ind][prevInd + 1] = max(take, notTake);
    }

    int longestSubsequence(int n, int a[])
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, -1, n, a, dp);
    }
};
