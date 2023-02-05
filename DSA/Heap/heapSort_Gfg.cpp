//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution
{
public:
    // current size of heap
    int size = 0;

    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n and arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n and arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

public:
    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    void heapSort(int arr[], int n)
    {
        // code here
        buildHeap(arr, n);

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]); // move current root to end
            heapify(arr, i, 0);
        }
    }
};

//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000], n, T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        Solution ob;
        ob.heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends