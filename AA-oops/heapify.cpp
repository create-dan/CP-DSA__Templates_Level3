// C++ code to depict
// the implementation of a max heap.

#include <bits/stdc++.h>
using namespace std;

// A class for Max Heap.
class MaxHeap {
	// A pointer pointing to the elements
	// in the array in the heap.
	int* arr;

	// Maximum possible size of
	// the Max Heap.
	int maxSize;

	// Number of elements in the
	// Max heap currently.
	int heapSize;

public:
	// Constructor function.
	MaxHeap(int maxSize);

	// Heapifies a sub-tree taking the
	// given index as the root.
	void MaxHeapify(int);

	// Returns the index of the parent
	// of the element at ith index.
	int parent(int i)
	{
		return (i - 1) / 2;
	}

	// Returns the index of the left child.
	int lChild(int i)
	{
		return (2 * i + 1);
	}

	// Returns the index of the
	// right child.
	int rChild(int i)
	{
		return (2 * i + 2);
	}

	// Removes the root which in this
	// case contains the maximum element.
	int removeMax();

	// Increases the value of the key
	// given by index i to some new value.
	void increaseKey(int i, int newVal);

	// Returns the maximum key
	// (key at root) from max heap.
	int getMax()
	{
		return arr[0];
	}

	int curSize()
	{
		return heapSize;
	}

	// Deletes a key at given index i.
	void deleteKey(int i);

	// Inserts a new key 'x' in the Max Heap.
	void insertKey(int x);
};

// Constructor function builds a heap
// from a given array a[]
// of the specified size.
MaxHeap::MaxHeap(int totSize)
{
	heapSize = 0;
	maxSize = totSize;
	arr = new int[totSize];
}

// Inserting a new key 'x'.
void MaxHeap::insertKey(int x)
{
	// To check whether the key
	// can be inserted or not.
	if (heapSize == maxSize) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// The new key is initially
	// inserted at the end.
	heapSize++;
	int i = heapSize - 1;
	arr[i] = x;

	// The max heap property is checked
	// and if violation occurs,
	// it is restored.
	while (i != 0 && arr[parent(i)] < arr[i]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

// Increases value of key at
// index 'i' to new_val.
void MaxHeap::increaseKey(int i, int newVal)
{
	arr[i] = newVal;
	while (i != 0 && arr[parent(i)] < arr[i]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

// To remove the root node which contains
// the maximum element of the Max Heap.
int MaxHeap::removeMax()
{
	// Checking whether the heap array
	// is empty or not.
	if (heapSize <= 0)
		return INT_MIN;
	if (heapSize == 1) {
		heapSize--;
		return arr[0];
	}

	// Storing the maximum element
	// to remove it.
	int root = arr[0];
	arr[0] = arr[heapSize - 1];
	heapSize--;

	// To restore the property
	// of the Max heap.
	MaxHeapify(0);

	return root;
}

// In order to delete a key
// at a given index i.
void MaxHeap::deleteKey(int i)
{
	// It increases the value of the key
	// to infinity and then removes
	// the maximum value.
	increaseKey(i, INT_MAX);
	removeMax();
}

// To heapify the subtree this method
// is called recursively
void MaxHeap::MaxHeapify(int i)
{
	int l = lChild(i);
	int r = rChild(i);
	int largest = i;
	if (l < heapSize && arr[l] > arr[i])
		largest = l;
	if (r < heapSize && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		MaxHeapify(largest);
	}
}

// Driver program to test above functions.
int main()
{
	// Assuming the maximum size of the heap to be 15.
	MaxHeap h(15);

	// Asking the user to input the keys:
	int k, i, n = 6, arr[10];
	cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14 \n";
	h.insertKey(3);
	h.insertKey(10);
	h.insertKey(12);
	h.insertKey(8);
	h.insertKey(2);
	h.insertKey(14);

	// Printing the current size
	// of the heap.
	cout << "The current size of the heap is "
		<< h.curSize() << "\n";

	// Printing the root element which is
	// actually the maximum element.
	cout << "The current maximum element is " << h.getMax()
		<< "\n";

	// Deleting key at index 2.
	h.deleteKey(2);

	// Printing the size of the heap
	// after deletion.
	cout << "The current size of the heap is "
		<< h.curSize() << "\n";

	// Inserting 2 new keys into the heap.
	h.insertKey(15);
	h.insertKey(5);
	cout << "The current size of the heap is "
		<< h.curSize() << "\n";
	cout << "The current maximum element is " << h.getMax()
		<< "\n";

	return 0;
}
