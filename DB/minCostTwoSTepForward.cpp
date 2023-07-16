#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"



int gcd(int a, int b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int expo(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}



void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n < 3)
    {
        cout << a[0] << endl;
        return;
    }

    vector<int> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[0] + a[2] + a[1];

    for (int i = 2; i < n - 1; i++)
    {
        dp[i] = min(dp[i - 2] + a[i], dp[i - 1] + a[i] + a[i + 1]);
    }

    dp[n - 1] = min(dp[n - 2], dp[n - 3] + a[n - 1]);
    cout << dp[n - 1] << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}