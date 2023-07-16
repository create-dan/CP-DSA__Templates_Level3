#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int k;
        cin >> k;
        int x;
        cin >> x;

        int arr[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int mx = (mp.size() - k) * x;
        int h = 0;

        cout << max(mx, h) << endl;
    }
    return 0;
}