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

        int getans(TreeNode *root, int curmax,int curmin)
        {
            if (root == nullptr)
            {
                return 0;
            }
            int posans = 0;
            // if (curmax > -1)
            //     posans = abs(root->val - curmax);
            curmax = max(curmax, root->val);
            curmin = min(curmin,root->val);
            posans=curmax-curmin;
            int lft = getans(root->left, curmax,curmin);
            int rht = getans(root->right, curmax,curmin);
            int mxans = max({ lft,
                rht,
                posans });
            // cout << mxans << endl;
            return mxans;
        }
    int maxAncestorDiff(TreeNode *root)
    {
        int ans = getans(root, 0,INT_MAX);
        return ans;
    }
};