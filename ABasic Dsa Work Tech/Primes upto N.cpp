#include <bits/stdc++.h>
using namespace std;

bool prime[10005];

void sieve()
{
    prime[0] = prime[1] = false;

    for (int i = 2; i < sqrt(10005); i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j < 10005; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

vector<int> primesUptoN(int n)
{

    memset(prime, true, sizeof(prime));

    sieve();

    // for(int i=1;i<=n;i++)
    // {
    // 	cout<<i<<" "<<prime[i]<<endl;
    // }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (prime[i])
            ans.push_back(i);
    }

    return ans;
}