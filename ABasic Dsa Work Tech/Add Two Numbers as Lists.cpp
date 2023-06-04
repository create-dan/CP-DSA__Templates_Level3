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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *temp = new ListNode(0);
    ListNode *curr = temp;

    int carry = 0;
    while (l1 != NULL or l2 != NULL)
    {
        int first = l1 != NULL ? l1->data : 0;
        int second = l2 != NULL ? l2->data : 0;

        int sum = first + second + carry;
        carry = sum / 10;

        ListNode *just = new ListNode(sum % 10);
        curr->next = just;
        curr = curr->next;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    if (carry)
    {
        curr->next = new ListNode(carry);
    }

    return temp->next;
}