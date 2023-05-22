#include <bits/stdc++.h>
using namespace std;

// Implement the below class
class MinStack
{
public:
    stack<int> elements;
    stack<int> minStack;

    void push(int x)
    {

        elements.push(x);
        if (minStack.empty() or x <= minStack.top())
        {
            minStack.push(x);
        }
    }
    void pop()
    {
        if (elements.empty())
            return;
        int top = elements.top();
        elements.pop();

        if (top == minStack.top())
        {
            minStack.pop();
        }
    }
    int top()
    {
        if (elements.empty())
            return -1;
        return elements.top();
    }
    int getMin()
    {
        if (minStack.empty())
            return -1;
        return minStack.top();
    }
};

/*
    // MinStack class and its object will be used as given below:
    MinStack *minStack = new MinStack();
    minStack->push(42);
    int top = minStack->top();
    int min = minStack->getMin();
    minStack->pop();
*/