//revised but not under stood properly



// https: // www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10&t=1450s&ab_channel=AdityaVerma

// https: // practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10&t=1450s&ab_channel=AdityaVerma
public:
    int minDifference(int arr[], int n)
    {

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        // subset Sum
        // int dp[n+1][sum+1];
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int diff = INT_MAX;
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n][i] == true)
            {
                diff = sum - 2 * i;
                break;
            }
        }

        return diff;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}
