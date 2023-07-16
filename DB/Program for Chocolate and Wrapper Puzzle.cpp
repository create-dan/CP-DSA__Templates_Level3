// https : // www.geeksforgeeks.org/program-chocolate-wrapper-puzzle/

#include <bits/stdc++.h>
using namespace std;

int wrapChoclates(int curr, int w)
{
    if (curr < w)
    {
        return 0;
    }

    int newChoc = curr / w;

    return newChoc + wrapChoclates(newChoc + curr % w, w);
}

int helper(int m, int p, int w)
{
    int curr = m / p;

    return curr + wrapChoclates(curr, w);
}

int main()
{
    int money, price, wrap;
    cin >> money >> price >> wrap;

    cout << helper(money, price, wrap) << endl;
}

// An efficient solution is to use a direct formula to find the number of chocolates.

// Find initial number of chocolates by
// dividing the amount with per piece cost.
// i.e. choc = money / price

// then apply below formula
// choc += (choc - 1)/(wrap - 1)
// In the above naive implementation, we noticed that after finding the initial number of chocolates, we recursively divide the number of chocolates by the number of wrappers required. until we left with 1 chocolate or wrapper.
// We are recomputing the values i.e. ((choc/wrap + choc%wrap)/wrap until we get 1.
// It is observed that we can get the result by just reducing the values of chocolates and wrappers by 1 and then divide them to get the result (choc-1)/(wrap-1)

// Below is the implementation of the above approach:

// Returns maximum number of chocolates we can eat
// with given money, price of chocolate and number
// of wrapprices required to get a chocolate.
int countMaxChoco(int money, int price, int wrap)
{
    // Corner case
    if (money < price)
        return 0;

    // First find number of chocolates that
    // can be purchased with the given amount
    int choc = money / price;

    // Now just add number of chocolates with the
    // chocolates gained by wrapprices
    choc = choc + (choc - 1) / (wrap - 1);
    return choc;
}