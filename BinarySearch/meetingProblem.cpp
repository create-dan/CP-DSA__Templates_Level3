
// 3
// 7 1 3 1 2 1
// Ans = 2.000000000000

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

pair<double, double> getInter(pair<double, double> p1, pair<double, double> p2)
{
    if (p1.first > p2.second || p2.first > p1.second)
    {
        return {1, -1};
    }

    pair<double, double> ans = {max(p1.first, p2.first),
                                min(p1.second, p2.second)};

    return ans;
}

const double pos = 1e17;
const double neg = -1e17;

bool check(double time, int a[], int b[], int n)
{
    pair<double, double> res = {neg, pos};
    for (int i = 0; i < n; i++)
    {
        pair<double, double> temp = {(double)a[i] - time * (double)b[i],
                                     (double)a[i] + time * (double)b[i]};
        res = getInter(res, temp);
        if (res.first > res.second)
            return false;
    }
    return true;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    double left = 0, right = 1e11;
    double res = right;
    for (int i = 0; i < 100; i++)
    {
        double mid = (left + right) / 2.0;
        if (check(mid, a, b, n))
        {
            res = min(res, mid);
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout.precision(10);
    cout << fixed << res << endl;

    return 0;
}