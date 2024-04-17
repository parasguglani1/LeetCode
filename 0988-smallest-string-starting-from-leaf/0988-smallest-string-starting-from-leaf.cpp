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

        vector<string> strs;

    void getstring(TreeNode *root, string &curr)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            curr += 'a' + root->val;

            string rev = curr;
            reverse(rev.begin(), rev.end());
            strs.push_back(rev);
            curr.pop_back();
        }
        else
        {
            curr += 'a' + root->val;

            getstring(root->left, curr);
            getstring(root->right, curr);
            curr.pop_back();
        }
    }

    string smallestFromLeaf(TreeNode *root)
    {

        string cur = "";

        getstring(root, cur);
        // for (auto x: strs)
        // {
        //     cout << x << ' ';
        // }

        sort(strs.begin(), strs.end());
        return strs[0];
    }
};