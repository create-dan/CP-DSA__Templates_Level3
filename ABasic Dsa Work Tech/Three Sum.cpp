#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    if (n < 3)
        return ans;
    if (nums[0] > 0)
        return ans;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            break;

        if (i > 0 and nums[i] == nums[i - 1])
            continue;
        int sum = 0;

        int low = i + 1, high = n - 1;

        while (low < high)
        {
            sum = nums[i] + nums[low] + nums[high];

            if (sum > 0)
            {
                high--;
            }
            else if (sum < 0)
            {
                low++;
            }
            else
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                int s = nums[low];
                int e = nums[high];

                while (low < high and nums[low] == s)
                    low++;
                while (low < high and nums[high] == e)
                    high--;
            }
        }
    }

    return ans;
}