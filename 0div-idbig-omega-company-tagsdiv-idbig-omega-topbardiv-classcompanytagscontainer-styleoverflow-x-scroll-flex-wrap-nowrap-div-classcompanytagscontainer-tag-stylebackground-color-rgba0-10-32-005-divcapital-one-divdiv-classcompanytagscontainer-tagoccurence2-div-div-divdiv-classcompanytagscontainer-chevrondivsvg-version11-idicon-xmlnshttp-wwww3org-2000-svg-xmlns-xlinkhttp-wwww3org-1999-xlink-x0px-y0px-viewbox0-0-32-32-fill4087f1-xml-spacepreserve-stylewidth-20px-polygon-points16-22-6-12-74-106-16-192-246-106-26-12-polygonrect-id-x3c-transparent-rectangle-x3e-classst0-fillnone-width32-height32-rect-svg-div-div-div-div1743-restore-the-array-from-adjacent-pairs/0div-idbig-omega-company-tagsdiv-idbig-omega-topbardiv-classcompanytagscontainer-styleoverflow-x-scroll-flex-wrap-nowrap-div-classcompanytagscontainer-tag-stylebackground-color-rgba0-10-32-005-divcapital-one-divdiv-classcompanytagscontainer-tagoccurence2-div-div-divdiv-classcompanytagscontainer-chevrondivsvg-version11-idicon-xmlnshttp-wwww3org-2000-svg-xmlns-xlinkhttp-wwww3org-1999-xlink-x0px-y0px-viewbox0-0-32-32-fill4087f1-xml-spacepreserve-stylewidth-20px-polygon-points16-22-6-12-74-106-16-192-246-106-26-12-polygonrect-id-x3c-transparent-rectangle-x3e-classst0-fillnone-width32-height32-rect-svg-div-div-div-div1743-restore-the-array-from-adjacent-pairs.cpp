class Solution
{
    public:
        unordered_map<int, vector<int>> graph;

        vector<int> restoreArray(vector<vector < int>> &adjacentPairs)
        {
            int n = adjacentPairs.size();
            if(n==1)
            {
                return adjacentPairs[0];
            }
            // vector<vector < int>> adj(n + 1);

            for (auto x: adjacentPairs)
            {
                int ff = x[0];
                int ss = x[1];

                graph[ff].push_back(ss);
                graph[ss].push_back(ff);
            }
            queue<int> q;
            map<int,int> vis;
            for(auto x:graph)
            {
                
                if (x.second.size() == 1)
                {
                    q.push(x.first);
                    vis[x.first] = 1;

                    break;
                }
            }
            vector<int> ans;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                ans.push_back(curr);

                for (auto x: graph[curr])
                {
                    if (!vis[x])
                    {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
            return ans;
        }
};