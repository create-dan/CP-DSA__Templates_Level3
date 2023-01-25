#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(2^n)

void findSubsequence(int ind, int a[], int n, vector<int> &ds)
{
    if (ind == n)
    {

        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // take it
    ds.push_back(a[ind]);
    findSubsequence(ind + 1, a, n, ds);
    ds.pop_back();
    findSubsequence(ind + 1, a, n, ds);
}

int32_t main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> ds;

    findSubsequence(0, a, n, ds);

    return 0;
}