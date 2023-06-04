
// The idea is to reverse each sub-list of length k recursively. 

// Traverse the list till a sub-list of length k is found. 
// If the length of a sub-list is less than k then simply return the head of the sublist.
// Otherwise, reverse this sub-list and recursively call the reverse function for the rest of the list 
// Link the two sub-lists together and return its head.

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

ListNode *reverseLinkedListKGroup(ListNode *head, int k)
{

    // base case
    if (head == NULL)
        return head;

    // for reversing first k nodes
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    ListNode *curr = head;

    // count remaining nodes
    int rem = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        rem++;
    }

    int count = 0;
    if (rem >= k)
    {

        while (curr != NULL and count < k)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;

            count++;
        }

        // recursive call
        if (nxt != NULL)
        {
            head->next = reverseLinkedListKGroup(nxt, k);
        }
    }
    else
    {
        return head;
    }

    return prev;
}