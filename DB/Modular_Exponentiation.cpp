// https: // www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    // Write your code here.

    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            // n is odd
            ans = (1LL * (ans) % m * (x) % m) % m;
        }

        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;
    }

    ans = ans % m;
    return ans;
}

int main()
{
    
}
  