#include <bits/stdc++.h>
using namespace std;

vector<int> kSubstringVowels(string s, int k)
{

    set<char> st = {'a', 'e', 'i', 'o', 'u'};

    int n = s.length();
    vector<int> ans;

    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        if (st.find(s[i]) != st.end())
            cnt++;
    }

    int ind = 0;

    ans.push_back(cnt);

    for (int i = k; i < n; i++)
    {
        if (st.find(s[i]) != st.end())
            cnt++;
        if (st.find(s[ind]) != st.end())
            cnt--;
        ind++;

        ans.push_back(cnt);
    }

    return ans;
}