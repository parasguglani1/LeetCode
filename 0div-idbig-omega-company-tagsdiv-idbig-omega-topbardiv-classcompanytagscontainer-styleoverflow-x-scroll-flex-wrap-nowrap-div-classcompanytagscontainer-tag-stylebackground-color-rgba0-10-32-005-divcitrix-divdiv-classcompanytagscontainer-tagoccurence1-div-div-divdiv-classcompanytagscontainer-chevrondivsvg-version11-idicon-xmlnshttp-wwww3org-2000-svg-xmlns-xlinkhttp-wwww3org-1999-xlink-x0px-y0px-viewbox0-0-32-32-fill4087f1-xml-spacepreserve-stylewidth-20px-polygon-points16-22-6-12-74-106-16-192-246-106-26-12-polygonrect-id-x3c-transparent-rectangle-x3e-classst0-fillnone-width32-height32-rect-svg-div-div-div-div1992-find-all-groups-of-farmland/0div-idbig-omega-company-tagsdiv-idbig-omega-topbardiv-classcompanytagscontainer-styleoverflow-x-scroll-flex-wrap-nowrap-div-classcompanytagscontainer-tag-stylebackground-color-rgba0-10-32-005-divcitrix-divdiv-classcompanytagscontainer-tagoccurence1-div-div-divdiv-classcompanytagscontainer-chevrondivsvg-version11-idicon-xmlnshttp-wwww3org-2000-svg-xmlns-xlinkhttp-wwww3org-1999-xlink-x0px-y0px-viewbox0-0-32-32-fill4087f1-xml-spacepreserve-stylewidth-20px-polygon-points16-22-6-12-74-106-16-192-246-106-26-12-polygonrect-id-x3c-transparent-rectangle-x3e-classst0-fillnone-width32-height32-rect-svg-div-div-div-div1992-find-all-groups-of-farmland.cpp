class Solution
{
    public:
    void dfs(vector<vector < int>> &land,vector<int> &curr,int x,int y,vector<vector<int>> &vis)
    {
        int n=vis.size();
        int m=vis[0].size();
        vis[x][y]=1;
        vector<int> delx={-1,0,1,0};
        vector<int> dely={0,-1,0,1};
        
        if(x+1==n &&y+1==m)
        {
            curr.push_back(x);
            curr.push_back(y);
        }
        else if(x+1==n &&land[x][y+1]==0)
        {
             curr.push_back(x);
            curr.push_back(y);
        }
        else if(y+1==m&&land[x+1][y]==0 )
        {
            curr.push_back(x);
            curr.push_back(y); 
        }
        else if(x<n-1 &&y<m-1 && land[x+1][y]==0 &&land[x][y+1]==0)
        {   curr.push_back(x);
            curr.push_back(y);
        }
        
        for(int i=0;i<4;i++)
        {
            int newx=delx[i]+x;
            int newy=dely[i]+y;
            if(newx<n &&newy<m && newx>=0 &&newy>=0 &&!vis[newx][newy] &&land[newx][newy]==1)
            {
            dfs(land, curr, newx, newy,vis);
            }
        }
        
        
    }
        vector<vector < int>> findFarmland(vector<vector < int>> &land)
        {
            vector<vector < int>> ans;
            int n = land.size();
            int m = land[0].size();
            vector<vector < int>> vis(n, vector<int> (m, 0));
            
            vector<int> curr;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!vis[i][j] &&land[i][j])
                    {
                        curr.push_back(i);
                        curr.push_back(j);

                        dfs(land, curr, i, j,vis);
                        ans.push_back(curr);
                        curr.clear();
                    }
                }
            }
            return ans;
        }
};