

// Revised

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N^3)
    Space Complexity: O(1)

    where N is the length of the array.
*/

#include <algorithm>

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long curSum = 0;

            for (int k = i; k <= j; k++)
            {
                curSum += arr[k];
            }

            maxSum = max(maxSum, curSum);
        }
    }

    return maxSum;
}

// starting a new subarray or extending the previous subarray


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            curr = max(nums[i], curr + nums[i]);
            ans = max(ans, curr);
        }

        return ans;
    }
};
