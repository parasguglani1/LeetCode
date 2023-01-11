class Solution {
public:
void dfs(int x,int par,vector<vector<int>>&adj,vector<bool>&has)
    {
        for(int k:adj[x])
        {
            if(k==par){continue;}
            dfs(k,x,adj,has);
            has[x] = (has[x]|has[k]);
        }
    }
    
    int solve(int x,int par,vector<vector<int>>&adj,vector<bool>&has)
    {
        if(!has[x]){return 0;}
        int ans=0;
        for(int k:adj[x])
        {
            if(k==par){continue;}
            if(has[k])
            {
                ans+= solve(k,x,adj,has);
            }
        }
        if(x==0)
        {
            return ans;
        }
        return ans+2;
    }

    int minTime(int n, vector<vector<int>>& edg, vector<bool>&has) 
    {
        vector<vector<int>>adj(n);
        for(vector<int>j:edg)
        {
            adj[j[0]].push_back(j[1]);
            adj[j[1]].push_back(j[0]);
        }
         dfs(0,0,adj,has);
          int ans=solve(0,0,adj,has);
        return ans;
        
    }

};