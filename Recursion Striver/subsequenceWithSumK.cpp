
#include <bits/stdc++.h>
using namespace std;

void findSubsequenceWithSumK(int ind, int a[], int n, vector<int> &ds, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (auto i : ds)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    // take it
    ds.push_back(a[ind]);
    findSubsequenceWithSumK(ind + 1, a, n, ds, sum + a[ind], k);

    ds.pop_back();
    findSubsequenceWithSumK(ind + 1, a, n, ds, sum, k);
}

int32_t
main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> ds;

    findSubsequenceWithSumK(0, a, n, ds, 0, k);

    return 0;
}