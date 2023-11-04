/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Codec
{
    public:

       	// Encodes a tree to a single string.
        string serialize(TreeNode *root)
        {
            if (!root)
            {
                return "";
            }

           	//store level seperated by -
            queue<TreeNode*> q;
            q.push(root);
            string ans = "";
            while (!q.empty())
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr)
                {
                    ans += to_string(curr->val) + ' ';
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else
                {
                    ans += "null ";
                }
            }
           	// cout<<ans<<endl;
            return ans;
        }

   	// Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {

       	// cout<<data<<endl;
        TreeNode *ans = nullptr;
        int n = data.size();
        if (n == 0) return ans;
        stringstream ss(data);
        string word;
        ss >> word;
        TreeNode *newNode = new TreeNode(stoi(word));
        queue<TreeNode*> q;
        ans = newNode;
        q.push(ans);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            ss >> word;
            if (word == "null")
            {
                curr->left = nullptr;
            }
            else
            {
                curr->left = new TreeNode(stoi(word));
                q.push(curr->left);
            }
            ss >> word;
            if (word == "null")
            {
                curr->right = nullptr;
            }
            else
            {
                curr->right = new TreeNode(stoi(word));
                q.push(curr->right);
            }
        }
        return ans;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));