// https: // leetcode.com/problems/maximum-product-subarray/description/

// Given an integer array nums, find a subarray that has the largest product, and return the product.

// Input : nums = [ 2, 3, -2, 4 ] Output : 6 Explanation : [ 2, 3 ] has the largest product 6.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int n = nums.size();
        int ans = INT_MIN;
        int mx = 1, mn = 1;
        for (int i = 0; i < n; i++)
        {
            int temp = mx;
            mx = max({nums[i], mx * nums[i], mn * nums[i]});
            mn = min({nums[i], temp * nums[i], mn * nums[i]});

            ans = max({ans, mx, mn});
        }

        return ans;
    }
};

int32_t main()
{


    return 0;
}