

// The approach used in this implementation is to maintain a linked list to store the elements of the queue.The qfront pointer points to the first node in the queue, and the rear pointer points to the last node.Each time an element is pushed into the queue, a new node is created and added to the rear of the queue.When an element is popped from the queue, the qfront pointer is updated to point to the next node, effectively removing the front element.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Queue
{
public:
    ListNode *qfront;
    ListNode *rear;
    int qsize = 0;
    int capacity = 0;

    Queue(int capacity)
    {
        qfront = rear = NULL;
        qsize = 0;
        this->capacity = capacity;
    }

    bool isEmpty()
    {
        return qsize == 0;
    }

    int size()
    {
        return qsize;
    }

    int front()
    {

        if (qfront == NULL)
            return -1;
        return qfront->data;
    }

    int back()
    {
        if (rear == NULL)
            return -1;
        return rear->data;
    }

    void push(int element)
    {

        ListNode *temp = new ListNode(element);
        if (rear == NULL)
        {
            qfront = rear = temp;
            qsize++;
            return;
        }

        rear->next = temp;
        rear = temp;
        qsize++;
    }

    void pop()
    {

        if (qfront == NULL)
            return;
        ListNode *temp = qfront;

        qfront = qfront->next;
        if (qfront == NULL)
        {
            rear = NULL;
        }

        qsize--;
    }
};