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
       void addroot(TreeNode *root, int val, int dep, int depth)
        {
            if (dep == depth - 1) {
                TreeNode * l=root->left;
                TreeNode * r=root->right;
                TreeNode *newl= new TreeNode(val);
                TreeNode *newr= new TreeNode(val);
                newl->left=l;
                newr->right=r;
                root->left=newl;
                root->right=newr;
            }
            else
            {

                if (root->left)
                {
                    addroot(root->left, val, dep + 1, depth);
                }
                if (root->right)
                {
                    addroot(root->right, val, dep + 1, depth);
                }
            }
        }

    TreeNode* addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }

        int dep = 1;
        addroot(root, val, dep, depth);
        return root;
    }
};