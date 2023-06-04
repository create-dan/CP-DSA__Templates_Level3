#include <bits/stdc++.h>
using namespace std;

int getKthElement(vector<int> &v1, vector<int> &v2, int k)
{

    int n = v1.size();
    int m = v2.size();

    // k--;

    int i = 0, j = 0;
    int ind = 0;

    while (i < n and j < m)
    {

        if (v1[i] <= v2[j])
        {

            ind++;
            if (ind == k)
                return v1[i];
            i++;
        }
        else
        {
            ind++;
            if (ind == k)
                return v2[j];
            j++;
        }
    }

    while (i < n)
    {
        ind++;
        if (ind == k)
            return v1[i];
        i++;
    }

    while (j < m)
    {
        ind++;
        if (ind == k)
            return v2[j];
        j++;
    }

    return -1;
}