// Example: – 4  {www.google.com, www.fb.com, www.twitter.com, www.google.com }

// Output:- 3  {www.google.com, www.fb.com, www.twitter.com}

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<string> helper(vector<string> &url, int n)
{

    map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[url[i]]++;
    }

    for(auto i : mp)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    vector<pair<string, int>> curr(mp.begin(), mp.end());


    sort(curr.begin(), curr.end(), cmp);

    // for(auto i : curr)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    vector<string> final;
    for (auto i : curr)
    {
        final.push_back(i.first);
    }

    return final;
}

int main()
{
    int n;
    cin >> n;

    vector<string> url(n);

    for (int i = 0; i < n; i++)
    {
        cin >> url[i];
    }

    vector<string> ans = helper(url, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}