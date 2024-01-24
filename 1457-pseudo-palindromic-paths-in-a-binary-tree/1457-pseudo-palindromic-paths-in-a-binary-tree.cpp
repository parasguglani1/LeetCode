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
        int getans(TreeNode *root, vector<int> &freq)
        {
            freq[root->val]++;
            if (root->left == nullptr && root->right == nullptr)
            {
                int oddcnt = 0;
                for (auto x: freq)
                {
                    if (x % 2)
                    {
                        oddcnt++;
                    }
                }
                freq[root->val]--;

                if (oddcnt < 2)
                {
                    return  1;
                }
                return 0;
            }
            int a = 0;
            if (root->left)
            {
                a += getans(root->left, freq);
            }
            if (root->right)
            {
                a += getans(root->right, freq);
            }
            freq[root->val]--;
            // cout << a << endl;
            return a;
        }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10, 0);
        int ans = 0;
        int bans=getans(root, freq);
        return bans;
    }
};