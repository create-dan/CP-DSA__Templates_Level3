#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    void traversal(Node *root, vector<string> &ans, string temp)
    {
        if (root->left == NULL and root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        traversal(root->left, ans, temp + '0');
        traversal(root->right, ans, temp + '1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int n)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < n; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;
        string temp = "";
        traversal(root, ans, temp);
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
