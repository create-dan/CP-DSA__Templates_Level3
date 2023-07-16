#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> ss, vector<int> tt)
    {
        for (int i = 0; i < 256; i++)
        {
            if (ss[i] < tt[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        string ans = "";
        if (t.size() > s.size())
            return ans;
        int count = INT_MAX;
        vector<int> ss(256, 0), tt(256, 0);
        for (int i = 0; i < t.size(); i++)
            tt[t[i]]++;
        int low = 0;
        int high = 0;
        while (high < s.size())
        {
            ss[s[high]]++;
            while (low < high && (ss[s[low]] == 0 || ss[s[low]] > tt[s[low]]))
            {
                ss[s[low]]--;
                low++;
            }
            if (check(ss, tt))
            {
                if (count > high - low)
                {
                    count = min(count, high - low + 1);
                    ans = s.substr(low, count);
                }
            }
            high++;
        }
        return ans;
    }
};