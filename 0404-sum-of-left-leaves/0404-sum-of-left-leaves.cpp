/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void getans(TreeNode* root,int &sum)
    {
        if(!root)
        {
            return;
        }
        if(root->left &&!root->left->left &&!root->left->right)
        {
            sum+=root->left->val;
        }
        getans(root->left,sum);
        getans(root->right,sum);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        getans(root,sum);
        return sum;
    }
};