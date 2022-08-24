#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

// 1024 5
// 2 64 2 2 2

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v;

    for (int i = 2; i <= n; i++)
    {

        while (n % i == 0)
        {

            n = n / i;
            v.push_back(i);
        }
    }

    if (v.size() < k)
    {
        cout << -1 << endl;
    }
    else
    {
        while (v.size() > k)
        {
            int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            v.push_back(a * b);
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}