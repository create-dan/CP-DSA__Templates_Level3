#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool helper(vector<int> &v, int mid, int days)
    {
        int n = v.size();
        int d = 1;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mid)
                return false;
            if (total + v[i] <= mid)
            {
                total += v[i];
            }
            else
            {
                d++;
                total = v[i];
            }
        }

        return d <= days;
    }

    int shipWithinDays(vector<int> &v, int days)
    {

        int low = 1, high = 50000 * 500;
        int ans;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (helper(v, mid, days))
            {
                ans = mid;
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        
    }

    return 0;
}