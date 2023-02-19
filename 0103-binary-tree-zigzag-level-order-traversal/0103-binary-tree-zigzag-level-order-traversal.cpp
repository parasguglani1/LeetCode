/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
            if (!root)
            {
                return {};
            }
            queue<TreeNode*> q;
            vector<vector < int>> ans;
            q.push(root);
            int step = 0;
            int count = 1;
            vector<int> temp;
            while (q.size() > 0)
            {
                TreeNode *top = q.front();
                q.pop();
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                temp.emplace_back(top->val);
                if (--count == 0)
                {
                    count = q.size();
                    if (step)
                        reverse(temp.begin(), temp.end());

                    ans.emplace_back(temp), temp.clear();
                    step ^= 1;
                }
            }
            return ans;
        }
};