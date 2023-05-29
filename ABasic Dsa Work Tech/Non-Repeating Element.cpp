// Given a sorted list of numbers in which all elements appear twice except one element that appears only once, find the number that appears only once.

// solution 1

#include <bits/stdc++.h>
using namespace std;

int findNonRepeatingElement(vector<int> &arr)
{

    int x = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        x ^= arr[i];
    }

    return x;
}

// solution 2

// This observation can be used to find the answer efficiently using binary search.

// Declare three variable low=0, high = n-1 and mid;
// While (low<=high) assign mid=(high+low)/2.
// If mid is even then check if arr[mid] and arr[mid+1] are equal. If yes, then the element must be in the second half otherwise the element must be in the first half.
// If mid is odd then check if arr[mid] and arr[mid-1] are equal. If yes, then the element must be in the second half otherwise the element must be in the first half.
// When low and high are equal, return the value of arr[low] as it is the only element that is not equal to its previous or next element.

// Time Complexity : O(log(n))

// C++(Iterative)
int findNonRepeatingElement(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (low == high)
        {
            return arr[mid];
        }
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
    }
}

// C++(Recursive) 
int binarySearch(vector<int> arr, int low, int high)
{
    if (high >= low)
    {
        int mid = (high + low) / 2;
        if (low == high)
        {
            return arr[mid];
        }
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                return binarySearch(arr, mid + 1, high);
            }
            else
            {
                return binarySearch(arr, low, mid);
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                return binarySearch(arr, mid + 1, high);
            }
            else
            {
                return binarySearch(arr, low, mid);
            }
        }
    }
}
int findNonRepeatingElement(vector<int> arr)
{
    int n = arr.size();
    return binarySearch(arr, 0, n - 1);
}
