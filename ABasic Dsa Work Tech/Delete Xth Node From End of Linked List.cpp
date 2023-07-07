
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

int length(ListNode *head)
{
    ListNode *curr = head;
    int cnt = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        cnt++;
    }

    return cnt;
}

ListNode *removeXthNodeFromEnd(ListNode *head, int x)
{

    int len = length(head);

    x = len - x - 1;
    if (x < 0)
    {
        return head->next;
    }

    ListNode *curr = head;

    while (x--)
    {
        curr = curr->next;
    }

    curr->next = curr->next->next;

    return head;
}