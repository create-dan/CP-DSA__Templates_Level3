#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

bool isPalindrome(string &s)
{
    string rev = s;
    reverse(s.begin(), s.end());

    return rev == s;
}

int countDigit(int n)
{
    return floor(log10(n) + 1);
}

int kadaneAlgo(int n, int a[], int num)
{
    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            curr++;
            ans = max(curr, ans);
        }
        else
        {
            curr = 0;
        }
    }

    return ans;
}

int xorOfNum(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans ^= i;
    }

    return ans;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    vector<int> range(1e6, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        range[x]++;
    }

    for (int gcd = 1e6; gcd >= 1; gcd--)
    {
        int cnt = 0;
        for (int i = gcd; i <= 1e6; i += gcd)
        {
            cnt += range[i];
        }
        if (cnt > 1)
        {
            cout << gcd << endl;
            break;
        }
    }

    return 0;
}