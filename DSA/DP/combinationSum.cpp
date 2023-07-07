

//revised


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// recursion
int helper(vector<int> &num, int tar)
{
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    int ans = 0;

    for (int i = 0; i < num.size(); i++)
    {

        ans += helper(num, tar - num[i]);
    }
    return ans;
}

// recursion+memo
int helperMem(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    if (dp[tar] != -1)
        return dp[tar];

    int ans = 0;

    for (int i = 0; i < num.size(); i++)
    {

        ans += helperMem(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

// tabulation

int helperTab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    //     return helper(num,tar);

    //     vector<int> dp(tar+1,-1);
    //     return helperMem(num,tar,dp);

    return helperTab(num, tar);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        
    }

    return 0;
}