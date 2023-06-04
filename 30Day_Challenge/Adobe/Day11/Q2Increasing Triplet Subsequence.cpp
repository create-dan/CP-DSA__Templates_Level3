// https: // leetcode.com/problems/increasing-triplet-subsequence/description/

// Given an integer array nums, return true if there exists a triple of indices(i, j, k)
// such that i < j < k and nums[i] < nums[j] < nums[k].If no such indices exists, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, vector<vector<int>> &dp, int prev, int ind)
    {

        // Memoization TLE
        if (ind == nums.size())
            return 0;

        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev])
        {
            take = 1 + helper(nums, dp, ind, ind + 1);
        }

        int notTake = helper(nums, dp, prev, ind + 1);
        return dp[ind][prev + 1] = max(take, notTake);
    }

    int helperTab(vector<int> &nums, vector<vector<int>> &dp)
    {

        //Tabulation TLE
        int n = nums.size();
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int len = 0 + dp[ind + 1][prev + 1];
                if (prev == -1 || nums[ind] > nums[prev])
                {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }

                dp[ind][prev + 1] = len;
            }
        }

        return dp[0][-1 + 1];
    }

    int binarySearch(vector<int> &nums)
    {
        //Accepted O(n*logn)
        // https://www.youtube.com/watch?v=on2hvxBXJH4&ab_channel=takeUforward
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }

    bool increasingTriplet(vector<int> &nums)
    {

        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int> (n+1,-1));
        // int maxLen= helper(nums,dp,-1,0);

        // vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        // int maxLen= helperTab(nums,dp);

        // using binary search
        int mxLen = binarySearch(nums);

        if (mxLen >= 3)
            return true;
        return false;
    }
};

int32_t main()
{

   

    return 0;
}
