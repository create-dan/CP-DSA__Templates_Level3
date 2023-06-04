#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> ans;
    void helper(TreeNode *root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        if (root->left != nullptr)
            helper(root->left);
        if (root->right != nullptr)
            helper(root->right);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {

        helper(root1);
        helper(root2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int32_t main()
{

    return 0;
}