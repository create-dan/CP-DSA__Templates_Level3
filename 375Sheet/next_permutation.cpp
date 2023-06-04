
//revised 1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // #SD
    // https://www.youtube.com/watch?v=LuLCLgMElus&ab_channel=takeUforward

    // brute force generate all
    // TC- N! * N (N! orders and N is the length of array)
    // Optimal - Linear Time Complexity

    // travers karo back se and find first index i , such that a[i] > a[i-1], lets say ind
    // phir se back se travser karo and ind pai jo hai usse bada element dekho
    // swap(ind1,ind2)
    // reverse(ind+1,last)
    //  [ 1, 3 , 5 , 4 ,2]
    //
    //        5
    //     3     4
    //  1           2

    // Time - O(N) multiple times

    void nextPermutation(vector<int> &nums)
    {

        int idx = -1;
        int n = nums.size();
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                idx = i - 1;
                break;
            }
        }

        if (idx == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int prev;
            for (int i = idx + 1; i < n; i++)
            {
                if (nums[i] > nums[idx])
                {
                    prev = i;
                }
            }
            swap(nums[idx], nums[prev]);
            reverse(nums.begin() + idx + 1, nums.end());
        }

        return;
    }
};
