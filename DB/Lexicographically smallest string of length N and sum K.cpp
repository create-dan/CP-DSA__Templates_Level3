#include <bits/stdc++.h>
using namespace std;

// Input: N = 5, K = 42
// Output: aaamz
// “aaany”, “babmx”, “aablz” etc. are also valid strings
// but “aaamz” is the lexicographically smallest.

// Input: N = 3, K = 25
// Output: aaw

class Solution
{
public:
    string getSmallestString(int n, int k)
    {

        string ans(n, ' ');

        int req = n - 1;
        int j = n - 1;

        while (k - req >= 26)
        {
            ans[j] = 'z';
            j--;
            k -= 26;
            req--;
        }

        if (req < 0)
            return ans;

        j = 0;
        while (j < req)
        {
            ans[j] = 'a';
            j++;
            k--;
        }

        ans[j] = 'a' + k - 1;

        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    cout << helper(n, k) << endl;
    return 0;
}