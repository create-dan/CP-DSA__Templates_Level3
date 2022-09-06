// 12, 44, 1, 6, 9
// Ans = 1 6 9 12 44

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int partition(int arr[], int s, int e)
{
    // finding pivot - start
    int pivot = arr[s];

    // count kitne number chote hai pivot se
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left mai sare chote and right mai bade
    int i = s, j = e;
    while (i < pivotIndex and j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex and j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int32_t main()
{

    int arr[5] = {12, 44, 1, 6, 9};
    int n = 5;

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}