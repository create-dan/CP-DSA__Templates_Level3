int findStep(int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;

    else
        return findStep(n - 3) + findStep(n - 2) + findStep(n - 1);
}

// Time Complexity : O(3n).
                  // The time complexity of the above solution is exponential, a close upper bound will be O(3n). From each state, 3 recursive function are called. So the upperbound for n states is O(3n).

int countWays(int n)
{
    int res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];

    return res[n];
}
