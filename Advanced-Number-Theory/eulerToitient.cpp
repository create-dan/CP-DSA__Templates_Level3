#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;







vector<bool> v(1e6 + 8, true);
void isPrime()
{
    v[0] = v[1] = false;
    for (int i = 2; i <= 1e6 + 8; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= 1e6 + 8; j += i)
            {
                v[j] = false;
            }
        }
    }

    // for (int i = 0; i < 20; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
}

int eulerTotient(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        int x = 0;
        while (n % i == 0)
        {
            n /= i;
            x = 1;
        }
        if (x)
        {
            result -= result / i;
        }
    }

    if (n > 1)
    {
        result -= result / n;
    }

    return result;
}

int32_t
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    isPrime();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (v[n])
        {
            cout << n - 1 << endl;
        }
        else
        {
            int ans = eulerTotient(n);
            cout << ans << endl;
        }
    }

    return 0;
}