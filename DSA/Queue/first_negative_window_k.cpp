#include <bits/stdc++.h>
using namespace std;






vector<long long> printFirstNegativeInteger(long long int a[],
                                            long long int n, long long int k)
{

    deque<long long int> dq;
    vector<long long int> ans;

    // process first window of k size
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.size() > 0)
    {
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = k; i < n; i++)
    {

        // removal of first number
        if (!dq.empty() and i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // addition

        if (a[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(a[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}