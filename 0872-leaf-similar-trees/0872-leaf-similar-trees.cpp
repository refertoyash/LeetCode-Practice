/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void leafs(TreeNode *root, vector<int> &seq)
        {
            if (root == NULL) return;
            if (root->left == NULL && root->right == NULL)
            {
                seq.push_back(root->val);
                return;
            }
            leafs(root->left, seq);
            leafs(root->right, seq);
            return;
        }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> temp1;
        vector<int> temp2;
        leafs(root1, temp1);
        leafs(root2, temp2);
        return (temp1 == temp2);
    }
};