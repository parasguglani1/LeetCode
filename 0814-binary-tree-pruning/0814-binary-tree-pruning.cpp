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
    bool dfs(TreeNode *root)
    {
        if (!root->left and!root->right) return root->val;
        int l = 0, r = 0;
        if (root->left) l = dfs(root->left);
        if (root->right) r = dfs(root->right);

        if (!l) root->left = NULL;
        if (!r) root->right = NULL;
        return root->val | l | r;
    }
    public:
        TreeNode* pruneTree(TreeNode *root)
        {
            if (dfs(root)) return root;
            return 0;
        }
};