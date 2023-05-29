// By using the Divide and Conquer approach, Merge Sort efficiently sorts the array in O(n log n) time complexity.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e)
{
    vector<int> temp(e - s + 1, 0);
    int left = s;
    int right = mid + 1;
    int ind = 0;
    while (left <= mid and right <= e)
    {
        if (arr[left] <= arr[right])
        {
            temp[ind] = arr[left];
            left++;
            ind++;
        }
        else
        {
            temp[ind] = arr[right];
            right++;
            ind++;
        }
    }

    while (left <= mid)
    {
        temp[ind] = arr[left];
        left++;
        ind++;
    }

    while (right <= e)
    {
        temp[ind] = arr[right];
        right++;
        ind++;
    }

    int j = s;
    for (int i = 0; i < temp.size(); i++)
    {
        arr[j] = temp[i];
        j++;
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

void mergeSort(vector<int> &arr)
{

    int n = arr.size();
    mergeSort(arr, 0, n - 1);
}