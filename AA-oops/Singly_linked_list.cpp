
// singly linked list
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int val)
{
    if (position == 1)
    {
        insertAtHead(head, val);
    }

    Node *temp = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, val);
    }

    Node *nodeToInsert = new Node(val);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *nodeTodelte = head;
        head = head->next;
        nodeTodelte->next = NULL;
        delete nodeTodelte;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }

    Node *nodeToDelte = temp->next;
    temp->next = temp->next->next;
    nodeToDelte->next = NULL;
    delete nodeToDelte;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp])
        {
            cout << "Loop present on " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
}

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL and fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if (fast == slow)
        {
            cout << "Cycle present at" << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *intersection = floydDetectLoop(head);

    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;

        return slow;
    }
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    print(head);
    insertAtHead(head, 100);
    insertAtHead(head, 200);
    print(head);
    insertAtPosition(tail,head, 1, 500);
    print(head);
}
