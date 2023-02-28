/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        vector<TreeNode*> ans;
    unordered_map<string, vector<TreeNode*>> mp;
    string traverse(TreeNode *root)
    {
        if (!root) return "";
        string curr = "";
        if (root->left)
        {
            curr += traverse(root->left);
            curr += 'L';
        }
        curr += to_string(root->val);
        if (root->right)
        {
            curr += traverse(root->right);
            curr += 'R';
        }
        mp[curr].push_back(root);
        if (mp[curr].size() == 2)
        {
            ans.push_back(mp[curr][0]);
        }
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode *root)
    {
        traverse(root);
        return ans;
    }
};