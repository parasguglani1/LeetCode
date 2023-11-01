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
        map<int,int> mp;
    void getmod(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
 
            mp[root->val]++;
 
        getmod(root->left);
        getmod(root->right);
        
    }

    vector<int> findMode(TreeNode* root) {
    getmod(root);
        vector<int> ans;
        int mxm=0;
        for(auto x:mp)
        {
            // cout<<x.first<<' '<<x.second<<endl;
            mxm=max(x.second,mxm);
            
        }
        // cout<<mxm<<endl;
        for(auto x:mp)
        {
            if(mxm==x.second)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};