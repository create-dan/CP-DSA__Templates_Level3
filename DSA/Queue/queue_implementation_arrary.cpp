#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

class Queue
{
public:
    int *arr;
    int qfront;
    int rear;
    int size;

    Queue()
    {
        // Implement the Constructor

        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return qfront == rear;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (rear == qfront)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

       return 0;
}