#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter Left Data : " << endl;
    root->left = buildTree(root->left);

    cout << "Enter right Data : " << endl;
    root->right = buildTree(root->right);
}

void levelOrderTraversel(node *root)
{
    queue<node *> q;
    q.push(root);

    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana wala level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// LNR

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// NLR
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// LRN
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// building tree from level order

void *buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter Data " << endl;
    int data;
    cin >> data;

    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    // root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1

    levelOrderTraversel(root); 

    // cout << "inorder print " << endl;
    // inorder(root);
    // cout << endl;

    // cout << "preorder print " << endl;
    // preorder(root);
    // cout << endl;

    // cout << "postorder print " << endl;
    // postorder(root);
    // cout << endl;
    return 0;
}