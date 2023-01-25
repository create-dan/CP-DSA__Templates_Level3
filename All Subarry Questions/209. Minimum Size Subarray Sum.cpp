// https: // leetcode.com/problems/minimum-size-subarray-sum/description/

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target.If there is no such subarray, return 0 instead.

// Input : target = 7, nums = [ 2, 3, 1, 2, 4, 3 ] Output : 2 Explanation : The subarray[4, 3] has the minimal length under the problem constraint.

#include <bits/stdc++.h>
using namespace std;




//O(nlog(n)) solution

//Dnyaneshwar
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int n = nums.size();

        //find prefix sum
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int ans = INT_MAX;
        for (int i = 0; i <= n; i++)
        {
            int ind = lower_bound(prefix, prefix + n + 1, prefix[i] + target) - prefix;
            int currInd = ind - i;

            if (ind != n + 1)
                ans = min(ans, currInd);
        }

        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};



//O(N)
class Solution
{
public:
    int minSubArrayLen(int k, vector<int> &nums)
    {

        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (right < nums.size())
        {
            sum += nums[right++];
            while (sum >= k)
            {
                int currLen = right - left;
                ans = min(ans, currLen);
                sum -= nums[left++];
            }
        }

        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};
int32_t main()
{

    return 0;
}