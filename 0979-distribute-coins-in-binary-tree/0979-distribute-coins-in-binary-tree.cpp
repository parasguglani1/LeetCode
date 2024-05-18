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
        int getans(TreeNode *root, int &ans)
        {
            if (!root)
            {
                return 0;
            }
            int left=getans(root->left,ans);
            int right=getans(root->right,ans);
            ans+=abs(left)+abs(right);
            return root->val-1+left+right;
        }
    int distributeCoins(TreeNode *root)
    {
        int ans = 0;
        getans(root, ans);
        return ans;
    }
};