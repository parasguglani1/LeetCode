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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> mp;
        map<int,int> freq;
        for(auto x:descriptions)
        {
            freq[x[1]]++;
        }
        int rootV=-1;
        for(auto x:descriptions)
        {
            if(freq.find(x[0])==freq.end())
            {
                rootV=x[0];
                break;
            }
        }
        
        for(auto x:descriptions)
        {
            TreeNode * parent=nullptr,*child=nullptr;
            if(mp.find(x[0])!=mp.end())
            {
                parent=mp[x[0]];
            }
             if(mp.find(x[1])!=mp.end())
            {
                child=mp[x[1]];
            }
            if(parent==nullptr)
            {
                parent=new TreeNode(x[0]);
                mp[x[0]]=parent;
            }
            if(child==nullptr)
            {
                child=new TreeNode(x[1]);
                mp[x[1]]=child;
            }
            if(x[2])
            {
                parent->left=child;
                
            }
            else
            {
                parent->right=child;
            }
        }
        return mp[rootV];
    }
};
