// https://leetcode.com/contest/weekly-contest-280/problems/removing-minimum-number-of-magic-beans/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minimumRemoval(vector<int> &v)
    {

        int n = v.size();
        sort(v.begin(), v.end());
        map<int, int> mp;
        for (auto i : v)
        {
            mp[i]++;
        }

        long long int ans = LONG_LONG_MAX;

        vector<long long int> pre(n + 1);
        pre[1] = v[0];
        for (int i = 2; i <= n; i++)
        {
            pre[i] = pre[i - 1] + v[i - 1];
        }

        //         for(int i=0;i<=n;i++)
        //         {
        //                cout<<pre[i]<<" ";
        //         }

        //         cout<<endl;

        for (int i = 1; i <= n; i++)
        {
            long long int piche = pre[i - 1];
            long long int aage = pre[n] - pre[i];
            long long curr = (1LL) * piche + (1LL) * aage - (1LL) * (n - i) * v[i - 1];
            // cout<<curr<<" ";
            ans = min(ans, curr);
        }
        // cout<<endl;

        return ans;
    }
};
