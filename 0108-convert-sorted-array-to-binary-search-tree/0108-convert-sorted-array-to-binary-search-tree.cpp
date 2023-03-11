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
     TreeNode* buildTree(int st,int end,vector<int> v)
    {
        if(st>end)
        {
            return nullptr;
        }
        int mid=(st+end)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=buildTree(st,mid-1,v);
        root->right=buildTree(mid+1,end,v);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
     int n=v.size();
        return buildTree(0,n-1,v);   
    }
};