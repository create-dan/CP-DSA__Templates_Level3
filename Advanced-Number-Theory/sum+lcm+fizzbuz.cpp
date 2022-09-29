// https : // atcoder.jp/contests/abc253/tasks/abc253_d

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}

int helper(int n, int x)
{
    int cnt = n / x;
    return (cnt * (cnt + 1)) / 2 * x;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    int sum1 = n * (n + 1) / 2;
    int curr = lcm(a, b);
    cout << sum1 - helper(n, a) - helper(n, b) + helper(n, curr);

    return 0;
}