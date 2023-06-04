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
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

ListNode *xthNodeFromEnd(ListNode *head, int x)
{

    int len = length(head);
    len = len - x - 1;

    if (len < 0)
        return head;

    while (len--)
    {
        head = head->next;
    }

    return head->next;
}