/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void inorder(TreeNode *root, vector<int> &temp)
        {
            if (root == NULL) return;
            inorder(root->left, temp);
            temp.push_back(root->val);
            inorder(root->right, temp);
        }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> nodes;
        inorder(root, nodes);
        int st = 0, end = nodes.size() - 1;
        while (st < end)
        {
            int obtained = nodes[st] + nodes[end];
            if (obtained == k) return true;
            else if (obtained > k) end--;
            else st++;
        }
        return false;
    }
};