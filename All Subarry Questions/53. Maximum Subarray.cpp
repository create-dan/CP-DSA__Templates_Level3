// https: // leetcode.com/problems/maximum-subarray/description/

// Input : nums = [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ] Output : 6 Explanation : The subarray[4, -1, 2, 1] has the largest sum 6.


#include <bits/stdc++.h>
using namespace std;


//Sudesh
class Solution
{

public:
    int maxSubArray(vector<int> &nums)
    {
        int csum = 0;
        int msum = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            csum += nums[i];
            msum = max(msum, csum);
            if (csum <= 0)
            {
                csum = 0;
            }
        }
        return msum;
    }
};

//DNYANESHWAR

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

int32_t main()
{

    

    return 0;
}