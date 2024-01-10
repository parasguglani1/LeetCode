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
    
    void convertToGraph(TreeNode* root, vector<vector<int>> &graph)
    {
        if(root==nullptr)
        {
            return;
        }
        int cur=root->val;
        if(root->left)
        {
            int dt=root->left->val;
            graph[dt].push_back(cur);
            graph[cur].push_back(dt);
            convertToGraph(root->left,graph);
            
            
        }
        if(root->right)
        {
            int dt=root->right->val;
            graph[dt].push_back(cur);
            graph[cur].push_back(dt);
            convertToGraph(root->right,graph);
            
        }
        
        
    }
    int amountOfTime(TreeNode* root, int start) {
        //graph then bfs;
        int n=100000;
        vector<vector<int>> graph(n+1,vector<int>());
        convertToGraph(root,graph);
        
        queue<pair<int,int>> q;
        int mins=0;
        q.push({start,mins});
        vector<int> vis(n+1,0);
        vis[start]=1;
 int ans=0;
        while(q.empty()==false)
        {
            auto tmp=q.front();
            q.pop();
            int curr=tmp.first;
            int mins=tmp.second;
            // vis[curr]=1;
            // ans=max(ans,mins);
            
            for(int i=0;i<graph[curr].size();i++)
            {
                int t=graph[curr][i];
                if(vis[t]==0)
                {
                    q.push({t,mins+1});
                    ans=max(ans,mins+1);
                    vis[t]=1;
                }
                    
            }
    
            
        }
        return ans;
        
    }
};