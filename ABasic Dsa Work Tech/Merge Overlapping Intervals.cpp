#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &v)
{

    sort(v.begin(), v.end());

    vector<vector<int>> ans;

    ans.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        int curr = v[i][0];
        int prev = ans.back()[1];

        if (curr <= prev)
        {
            ans.back()[1] = max(v[i][1], prev);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }

    return ans;
}