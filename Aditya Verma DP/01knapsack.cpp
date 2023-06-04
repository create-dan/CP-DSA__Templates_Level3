//revised

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int dp[1002][1002];

    int helper(int W, int wt[], int val[], int n)
    {
        if (W == 0 || n == 0)
            return 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        // include
        int include;
        int exclude;
        if (wt[n - 1] <= W)
        {
            include = val[n - 1] + helper(W - wt[n - 1], wt, val, n - 1);
            exclude = helper(W, wt, val, n - 1);
            return dp[n][W] = max(include, exclude);
        }
        else if (wt[n - 1] > W)
        {
            return dp[n][W] = helper(W, wt, val, n - 1);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(W, wt, val, n);
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
