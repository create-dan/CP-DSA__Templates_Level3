#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main()
{
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;

    map<char, vector<int>> mp;

    for (int i = l-1; i <= r-1; i++)
    {
        mp[s[i]].push_back(i);
    }

    int cnt = 0;
    for (auto i : mp)
    {
        int curr = i.second.size();
        int total = curr * (curr + 1) / 2;
        cnt += total;
    }
    cout<<cnt<<endl;

    return 0;
}