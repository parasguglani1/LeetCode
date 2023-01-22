/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
#define ll long long
class Solution
{
    public:
        ll maximum(TreeNode *root)
        {
            if (root == NULL)
            {
                return LLONG_MIN;
            }
            return max((ll)root->val, max((ll)maximum(root->left), (ll)maximum(root->right)));
        }
    ll minimum(TreeNode *root)
    {
        if (root == NULL)
        {
            return LLONG_MAX;
        }
        return min((ll)root->val, min(minimum(root->left), minimum(root->right)));
    }
    bool isValidBST(TreeNode *root)
    {

        if (root == NULL)
        {
            return true;
        }
        ll leftMax = maximum(root->left);
        ll rightMin = minimum(root->right);

        bool ans = (root->val > leftMax) && (root->val < rightMin) && isValidBST(root->left) && isValidBST(root->right);
        return ans;
    }
};