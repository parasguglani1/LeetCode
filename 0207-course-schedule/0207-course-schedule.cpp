class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        //do topo sort
        
        vector<vector<int>> adj(n);
        
        int m=edges.size();
        vector<int> indegree(n,0);
        for(int i=0;i<m;i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
        }
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
             
    
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            for(int i=0;i<adj[curr].size();i++)
            {
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0)
                {
                    q.push(adj[curr][i]);
                    
                }
                
            }
            
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]>0)
            {
                return false;
            }
        }
        
        return true;
        

        
        
    }
};