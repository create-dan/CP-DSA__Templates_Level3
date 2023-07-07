#include <bits/stdc++.h>
using namespace std;

vector<int> getNextGreaterElement(vector<int> &v)
{

    int n = v.size();
    stack<int> st;
    vector<int> ans(n);
    ans[n - 1] = -1;
    st.push(v[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() and st.top() <= v[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(v[i]);
    }

    return ans;
}