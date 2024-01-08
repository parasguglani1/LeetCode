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
    
    void getInorder(TreeNode* root, vector<int> &inorder)
    {
        if(root==nullptr)
        {
            return;
        }
        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
            
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inorder;
    getInorder(root,inorder); 
        int ans=0;
        for(int i =0;i<inorder.size();i++)
        {
            if(inorder[i]<=high && inorder[i]>=low)
            {
                ans+=inorder[i];
            }
        }
        return ans;
    }
};