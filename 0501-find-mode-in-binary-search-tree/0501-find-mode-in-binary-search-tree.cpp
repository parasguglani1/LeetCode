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
        vector<int> in;
        void inorder(TreeNode *root)
        {
            if (!root)
            {
                return;
            }

            inorder(root->left);

            in .push_back(root->val);
            inorder(root->right);
        }

    vector<int> findMode(TreeNode *root)
    {

        inorder(root);
        vector<int> ans;
        // cout<<in.size()<<endl;
        if(in.size()==1)
        {
            return {in[0]};
        }
        int mxm = 1;
        int cnt = 1;

        for (int i = 1; i < in.size(); i++)
        {
            if (in[i] == in[i - 1])
            {
                cnt++;
                if (mxm < cnt)
                {
                    mxm = cnt;
                }
            }
            else
            {
                cnt = 1;
            }
        }
        cout<<mxm<<endl;
cnt=1;
        for (int i = 1; i < in.size(); i++)
        {
            if (in[i] == in[i - 1])
            {
                cnt++;
                cout<<cnt<<endl;
                if (mxm == cnt)
                {
                    ans.push_back(in[i]);
                }
            }
            else
            {
                cnt = 1;
            }
        }
        if(mxm==1)
        {
            return in;
        }

        return ans;
    }
};