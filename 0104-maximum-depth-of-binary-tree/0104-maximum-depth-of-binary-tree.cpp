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
    int maxD(TreeNode* root, int &count)
    {
        if(!root)
        {
            return 0;
        }
         count=max(maxD(root->left,count),maxD(root->right,count))+1;
        return count;
        
        
    }
    int maxDepth(TreeNode* root) {
        int count=0;
        maxD(root,count);
        return count;
    }
};