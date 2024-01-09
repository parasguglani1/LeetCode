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
        void getinorder(TreeNode *root, vector<int> &v)
        {
            if (root == nullptr)
            {
                return;
            }
            getinorder(root->left, v);

            if (root->left == nullptr && root->right == nullptr)
            {
                v.push_back(root->val);
            }
            getinorder(root->right, v);
        }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> inorder1, inorder2;
        getinorder(root1, inorder1);
        getinorder(root2, inorder2);
        return inorder1 == inorder2;
    }
};