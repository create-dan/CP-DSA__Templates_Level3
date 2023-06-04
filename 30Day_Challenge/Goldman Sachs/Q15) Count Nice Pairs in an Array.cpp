// https: // leetcode.com/problems/count-nice-pairs-in-an-array/description/

// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

// A[i] + rev(A[j]) == A[j] + rev(A[i])
// A[i] - rev(A[i]) == A[j] - rev(A[j])
// B[i] = A[i] - rev(A[i])

// Then it becomes an easy question that,
// how many pairs in B with B[i] == B[j]

#include <bits/stdc++.h>    
using namespace std;

class Solution
{
public:
    int rev(int a)
    {
        int b = 0;
        while (a > 0)
        {
            b = b * 10 + (a % 10);
            a /= 10;
        }
        return b;
    }
    int countNicePairs(vector<int> &nums)
    {

        int n = nums.size();

        int M = 1e9 + 7;

        int ans = 0;
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {

            int num1 = nums[i];

            int num2 = rev(num1);

            // mp[num1-num2]++;
            nums[i] = num1 - num2;
        }

        // for(auto i : mp)
        // {
        //      ans = (ans%M + (((i.second)*(1LL) * (i.second-1))/2)%M)%M;

        // }

        for (int i = n - 1; i >= 0; i--)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
            {
                ans = (ans + (mp[nums[i]] - 1)) % M;
            }
        }

        return ans;
    }
};