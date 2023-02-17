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
class Solution
{
    public:
        vector<int> st;
    void inorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
            inorder(root->left);
        st.push_back(root->val);
        
        if (root->right)
            inorder(root->right);
        
    }

    int minDiffInBST(TreeNode *root)
    {
        inorder(root);
        
        int mn = INT_MAX;
        int n = st.size();
        
        // for (int i = 0; i < n; i++)
        // {
        //     cout << st[i] << " ";
        // }
        for (int i = 0; i < n - 1; i++)
        {
            mn = min(mn, abs(st[i + 1] - st[i]));
        }
        return mn;
    }
};