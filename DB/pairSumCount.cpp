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

// A = [1, 9, 8, 100, 2], should return 2: the pairs are [1, 9] and [8, 2] for a sum of 10
// A = [2, 2, 2, 3], should return 1: [2, 2] (sum 4) OR [2, 3] (sum 5). Notice we can only form sum 4 once since there is overlap between the elements
// A = [2, 2, 2, 2, 2], should return 2: [2, 2] and [2, 2] for a sum for 4. The fifth 2 is not used, while the first four 2's are used.

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maximum = INT_MIN;
    int minimum = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        maximum = max(maximum, arr[i]);
        minimum = min(minimum, arr[i]);
    }

    vector<int> freq(maximum + 1, 0);

    // Count the frequency
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    int result = 0;

    // Every possible sum of pairs
    for (int sum = 2 * minimum; sum <= 2 * maximum; sum++)
    {
        // Count of pairs with given sum
        int pair = 0;

        for (int num = 1; num < (sum + 1) / 2; num++)
        {
            // Check for a possible pair
            if (sum - num <= maximum)
            {
                // Update count of pair
                pair += min(freq[num], freq[sum - num]);
            }
        }

        if (sum % 2 == 0)
        {
            pair += freq[sum / 2] / 2;
        }

        // Update the result
        result = max(result, pair);
    }

    cout << result << endl;
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