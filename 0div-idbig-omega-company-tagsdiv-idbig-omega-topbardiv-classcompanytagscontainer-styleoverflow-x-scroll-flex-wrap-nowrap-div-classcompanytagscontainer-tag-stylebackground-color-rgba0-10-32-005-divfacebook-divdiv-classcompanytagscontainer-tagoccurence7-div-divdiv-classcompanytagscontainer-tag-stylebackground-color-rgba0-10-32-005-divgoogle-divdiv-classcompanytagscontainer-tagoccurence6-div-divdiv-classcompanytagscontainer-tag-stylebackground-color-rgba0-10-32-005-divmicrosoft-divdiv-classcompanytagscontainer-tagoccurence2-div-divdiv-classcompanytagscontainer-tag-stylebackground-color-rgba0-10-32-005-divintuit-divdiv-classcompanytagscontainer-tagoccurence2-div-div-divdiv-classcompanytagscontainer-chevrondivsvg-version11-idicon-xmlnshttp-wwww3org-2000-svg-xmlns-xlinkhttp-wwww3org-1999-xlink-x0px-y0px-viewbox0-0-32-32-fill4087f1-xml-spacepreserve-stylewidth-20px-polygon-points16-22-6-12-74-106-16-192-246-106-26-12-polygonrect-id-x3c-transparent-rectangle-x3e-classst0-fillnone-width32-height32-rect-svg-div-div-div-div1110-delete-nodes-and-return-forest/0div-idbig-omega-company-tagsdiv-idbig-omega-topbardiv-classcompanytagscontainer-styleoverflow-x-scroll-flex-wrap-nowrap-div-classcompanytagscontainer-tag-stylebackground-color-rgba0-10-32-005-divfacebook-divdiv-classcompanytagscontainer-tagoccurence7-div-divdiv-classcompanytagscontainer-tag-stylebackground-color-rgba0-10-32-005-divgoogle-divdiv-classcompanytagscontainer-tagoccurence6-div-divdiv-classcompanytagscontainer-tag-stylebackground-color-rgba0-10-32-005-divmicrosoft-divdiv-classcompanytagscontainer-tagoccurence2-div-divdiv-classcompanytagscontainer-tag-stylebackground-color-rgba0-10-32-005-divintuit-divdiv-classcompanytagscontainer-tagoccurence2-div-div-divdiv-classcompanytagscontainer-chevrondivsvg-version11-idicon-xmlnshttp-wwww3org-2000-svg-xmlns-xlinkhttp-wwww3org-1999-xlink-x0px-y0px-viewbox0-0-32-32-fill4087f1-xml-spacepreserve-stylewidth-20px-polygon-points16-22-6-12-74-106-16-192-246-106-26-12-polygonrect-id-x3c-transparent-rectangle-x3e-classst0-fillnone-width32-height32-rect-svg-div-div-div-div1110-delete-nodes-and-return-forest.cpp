/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    vector<TreeNode*> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        set<int> st;
        for (auto &x: to_delete)
        {
            st.insert(x);
        }
        vector<TreeNode*> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            auto tp=q.front();
            q.pop();
            if(tp->left)
            {
                q.push(tp->left);
                if(st.find(tp->left->val)!=st.end())
                {
                    tp->left=NULL;
                }
            }
            if(tp->right)
            {
                q.push(tp->right);
                if(st.find(tp->right->val)!=st.end())
                {
                    tp->right=NULL;
                }
            }
            
            if(st.find(tp->val)!=st.end())
            {
                if(tp->left)
                {
                    ans.push_back(tp->left);
                }
                if(tp->right)
                {
                    ans.push_back(tp->right);
                }
            }
            else if(ans.empty())
            {
                ans.push_back(tp);
            }
        }
        return ans;
    }
};