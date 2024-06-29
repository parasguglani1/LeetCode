class Solution
{
    vector<int> getAncestors(int cur, vector<vector < int>> &graph, int n)
    {
        vector<int> vis(n, 0);
        queue<int> q;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            vis[graph[cur][i]] = 1;
            q.push(graph[cur][i]);
        }

        while (!q.empty())
        {
            int tp = q.front();
            q.pop();
        // cout<<tp<<endl;
            for (int i = 0; i < graph[tp].size(); i++)
            {
                if (!vis[graph[tp][i]])
                {
                    vis[graph[tp][i]] = 1;
                    q.push(graph[tp][i]);
                }
            }
        }
        vector<int> ancestors;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] && i != cur)
            {
                ancestors.push_back(i);
            }
        }
        return ancestors;
    }
    public:
        vector<vector < int>> getAncestors(int n, vector<vector < int>> &edges)
        {
            vector<vector < int>> ans(n, vector<int> ());
            int m = edges.size();
            vector<vector < int>> graph(n, vector<int> ());
            for (auto x: edges)
            {
                graph[x[1]].push_back(x[0]);
            }
            // for(int i=0;i<n;i++)
            // {
            //     cout<<i<<"-->";
            //     for(int j=0;j<graph[i].size();j++)
            //     {
            //         cout<<graph[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            for (int i = 0; i < n; i++)
            {
                ans[i] = getAncestors(i, graph, n);
            }
            return ans;
        }
};