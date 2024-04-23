class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1)
        {
            return {0};
        }
        unordered_map<int,vector<int>> graph;
        vector<int> deg(n,0);
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++; deg[v]++;
            
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
            {
                q.push(i);
            }
        }
        
        int remNodes=n;
        while(remNodes>2)
        {
            int sz=q.size();
            remNodes-=sz;
            
            for(int i=0;i<sz;i++)
            {
                int last=q.front();
                q.pop();
                for(int x: graph[last])
                {
                    deg[x]--;
                    if(deg[x]==1)
                    {
                        q.push(x);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};