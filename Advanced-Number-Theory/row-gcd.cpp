#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

// gcd(a,b) = gcd(b,a%b) = gcd(a,|a-b|)= gcd(b,|a-b|)

// gcd(a1,a2,a3) = gcd(a1,|a1-a2| , |a1-a3|)
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int curr = 0;
    for (int i = 1; i < n; i++)
    {
        curr = __gcd(curr, abs(a[i] - a[0]));
    }
    // cout << curr << endl;

    for (int i = 0; i < m; i++)
    {
        int ans = __gcd(a[0] + b[i], curr);
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}