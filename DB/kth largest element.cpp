// You are given an array arr containing N distinct integers. You must perform the following operations on the array:

// For each pair of integers of the array, you must find the absolute difference D between these integers and insert D into the array. If D is already an element of the array, then you are not required to insert D into the array
// You repeat task 1 until the array cannot be modified further. This implies that the absolute
// difference between any two elements in the array is already an element of the array.
// Write a program to find the Kth the largest element of the final array after the array cannot be modified further. If there is no such element then print -1.

// Input: [ 5 7 9] ,k=3
// output : 7
// 1st modification : 2 4 5 7 9
// 2nd modification :1 2 3 4 5 7 9
// 3rd modification :1 2 3 4 5 6 7 8 9


//brute force
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[i] = x;
        // cin >> a[i];
    }

    int k;
    cin >> k;

    while (true)
    {
        bool modified = false;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = abs(a[j] - a[i]);

                if (find(a.begin(), a.end(), diff) == a.end())
                {
                    a.push_back(diff);
                    modified = true;
                }
            }
        }

        if (!modified)
        {
            break;
        }
    }

    sort(a.begin(), a.end());
    if (a.size() >= k)
    {
        cout << a[a.size() - k] << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}





//optimize

