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
        TreeNode* adding(TreeNode *node, TreeNode *root, int val, int currd, int tdepth)
        {
            if (tdepth == 1)
            {
                TreeNode *nroot = new TreeNode(val);
                nroot->left = root;
                return nroot;
            }

            if (node == NULL)
            {
                return root;
            }

            if (currd == tdepth - 1)
            {
                TreeNode *left_side = node->left;
                TreeNode *right_side = node->right;
                TreeNode *cl = new TreeNode(val);
                TreeNode *cr = new TreeNode(val);
                cl->left = left_side;
                cr->right = right_side;
                node->left = cl;
                node->right = cr;
                return root;
            }
            adding(node->left, root, val, currd + 1, tdepth);
            adding(node->right, root, val, currd + 1, tdepth);
            return root;
        }

    TreeNode* addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode *froot = adding(root, root, val, 1, depth);
        return froot;
    }
};