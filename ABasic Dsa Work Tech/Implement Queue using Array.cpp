#include <bits/stdc++.h>
using namespace std;

// Implement the Queue class
class Queue
{

    int *arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    int size()
    {
        return currentSize;
    }

    int front()
    {
        if (isEmpty())
            return -1;
        return arr[frontIndex];
    }

    int back()
    {
        if (isEmpty())
            return -1;
        return arr[rearIndex];
    }

    void push(int element)
    {
        if (currentSize == capacity)
            return;

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = element;
        currentSize++;
    }

    void pop()
    {
        if (isEmpty())
            return;
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }
};