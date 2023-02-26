/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> ans;

    void bfs(TreeNode *root)
    {
        if (root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {

            vector<int> temp;
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
               	//process current one

                TreeNode *curr = q.front();
                temp.push_back(curr->val);
                q.pop();
                if (curr->left != NULL )
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL )
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
        }
    }

    vector<vector < int>> levelOrder(TreeNode *root)
    {

        bfs(root);
        return ans;
    }
};