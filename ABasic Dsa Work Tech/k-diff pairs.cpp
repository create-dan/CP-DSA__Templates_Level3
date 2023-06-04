#include <bits/stdc++.h>
using namespace std;

// https : // workat.tech/problem-solving/practice/k-diff-pairs
// look at the another approach using 2 pointers and sorting

int kDiffPairs(vector<int> &nums, int k)
{

    int n = nums.size();
    int ans = 0;
    map<int, int> mp;

    for (auto i : nums)
        mp[i]++;

    for (auto i : mp)
    {
        if (k == 0)
        {
            if (i.second > 1)
                ans++;
        }
        else
        {
            if (mp.find(i.first + k) != mp.end())
                ans++;
        }
    }

    return ans;
}







//2nd

int kDiffPairs(vector<int> &A, int k)
{
    // add your logic here
    int n = A.size();
    int i = 0, j = 1;
    int count = 0;
    while (j < n)
    {
        while (j < (n - 1) && A[j] == A[j + 1])
        {
            j++;
        }
        int diff = A[j] - A[i];
        if (diff == k)
        {
            count++;
            i++;
            j++;
        }
        else if (diff < k)
        {
            j++;
        }
        else
        {
            i++;
        }
        if (i == j)
        {
            j++;
        }
    }

    return count;
}