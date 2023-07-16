#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int M = 1e9 + 7;

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " || ";
    __f(comma + 1, args...);
}

bool isPalindrome(string &s)
{
    string rev = s;
    reverse(s.begin(), s.end());

    return rev == s;
}

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

int mod_add(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

// Given an integer N, the task is to find two integers with minimum possible sum such that their product is strictly greater than N.

// Examples:

// Input: N = 10
// Output: 7
// Explanation: The integers are 3 and 4. Their product is 3 × 4 = 12, which is greater than N.

// Input: N = 1
// Output: 3
// Explanation: The integers are 1 and 2. Their product is 1 × 2 = 2, which is greater than N.

void solve()
{
    int n;
    cin >> n;

    int low = 1, high = n;

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        bug(mid);
        if (mid * mid >= n)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }

    // now we have first element

    int first = high;
    low = 0, high = n;

    bug(first);

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (first * mid > n)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }

    int second = high;
    cout << first + second << endl;
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