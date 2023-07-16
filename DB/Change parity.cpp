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

set<int> st;

void helper()
{

    for (int i = 1; i <= 10000; i++)
    {
        st.insert(i * i);
    }
}

void solve()
{
    int x;
    cin >> x;

    auto it = st.lower_bound(x);
    if (*it == x)
    {
        // if x is a square, output n+1
        cout << x + 1 << endl;
        return;
    }
    else
    {
        // else output the next square number > n
        cout << *it << endl;
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    helper();
    while (t--)
    {
        solve();
    }

    return 0;
}