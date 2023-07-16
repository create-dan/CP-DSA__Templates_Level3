#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == 0)
                ans = 0;
            else
                ans = __gcd(arr[i], ans);
        }

        if (ans == 1)
        {
            cout << "FINITE" << endl;
        }
        else
        {
            cout << "INFINITE" << endl;
        }
    }
}
