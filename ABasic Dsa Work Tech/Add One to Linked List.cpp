
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

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

ListNode *addOneToList(ListNode *head)
{

    ListNode *rev = reverse(head);
    ListNode *temp = rev;

    int carry = 1;
    while (rev != NULL)
    {
        int curr = rev->data;
        rev->data = (curr + carry) % 10;
        carry = (curr + carry) / 10;
        if (rev->next != NULL)
            rev = rev->next;
        else
            break;
    }

    if (carry)
    {
        ListNode *curr = new ListNode(carry);
        rev->next = curr;
    }

    return reverse(temp);
}