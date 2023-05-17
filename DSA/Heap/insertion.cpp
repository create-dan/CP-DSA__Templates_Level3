#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    // constructor
    heap()
    {
        arr[0] = 1;
        size = 0;
    }
    void insert(int val)
    {
        // new elment add ho raha hai to size increase
        size++;

        // jo current index hai
        int index = size;

        // index mai val dal do
        arr[index] = val;

        // abhi usko check karo whether new element is at correct position
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteNode()
    {
        if (size == 0)
        {
            cout << "EMPTY()" << endl;
            return;
        }

        // last node ko uthake root mai dal do
        arr[1] = arr[size];

        // last node ko hata do
        size--;

        // take root node to it's correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size and arr[leftIndex] > arr[i])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size and arr[rightIndex] > arr[i])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    // heapify algoritms

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    // is largest index ko sahi jagah pai leke jana hai
    int largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n and arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= n and arr[right] > arr[largest])
    {
        largest = right;
    }

    // agar largest update ho gaya hai to swap and call heapify for largest recursively
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sort
void heapSort(int arr[], int n)
{
    int t = n;
    while (t > 1)
    {
        swap(arr[1], arr[t]);
        t--;
        heapify(arr, t, 1);
    }
}

int main()
{
    heap h;
    h.insert(1);
    h.insert(10);
    h.insert(100);
    h.print();
    h.deleteNode();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = 6 / 2; i > 0; i--)
    {
        heapify(arr, 5, i);
    }
    cout << "after heapify" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    //  output--
    // after heapify
    // 55 53 54 52 50
    cout << endl;

    // heap sort
    heapSort(arr, n);
    
    return 0;
}