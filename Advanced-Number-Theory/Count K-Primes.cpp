
// https : // www.codechef.com/problems/KPRIME?tab=statement

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int sz = 100001;
int prime[sz] = {0};

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    int ans = 0;
    for (int i = a; i <= b; i++)
    {

        if (prime[i] == k)
        {
            ans++;
        }
    }

    cout << ans << endl;
}

int32_t main()
{

    for (int i = 2; i < sz; i++)
    {

        if (prime[i] == 0)
        {
            for (int j = i; j < sz; j += i)
            {
                prime[j]++;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
