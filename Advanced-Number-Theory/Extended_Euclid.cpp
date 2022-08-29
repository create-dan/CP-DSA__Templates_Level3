#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int x = 1, y = 0;
    int ans = gcd(a, b, x, y);
    cout << x << " " << y << " " << ans << endl;

    return 0;
}