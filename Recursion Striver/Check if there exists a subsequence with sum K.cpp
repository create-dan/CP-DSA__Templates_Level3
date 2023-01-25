#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(int ind, vector<int> &arr, int n, int k, int sum)
    {
        if (sum > k)
            return false;
        if (sum == k)
            return true;
        if (ind == n)
        {
            if (sum == k)
            {
                return true;
            }
            return false;
        }

        if (helper(ind + 1, arr, n, k, sum + arr[ind]) == true)
            return true;
        if (helper(ind + 1, arr, n, k, sum) == true)
            return true;
        return false;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {

        return helper(0, arr, n, k, 0);
    }
};

int32_t main()
{

    

    return 0;
}