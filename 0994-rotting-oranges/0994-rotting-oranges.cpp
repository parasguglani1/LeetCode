class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int> >q;
        int frcnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pair<pair<int,int>,int> st= {{i,j},0};
                    q.push(st);
                    vis[i][j]=1;
                }
                if(grid[i][j]==1)
                {
                    frcnt++;
                }
            }
        }
        int ans=0;
        int delrow[4]={0,0,-1,1};
        int delcol[4]={1,-1,0,0};
        while(!q.empty())
        {
            
            auto c=q.front();
            q.pop();
            auto coord=c.first;
            int time=c.second;
            int row=coord.first,col=coord.second;
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    int ntime=time+1;
                    pair<pair<int,int>,int> pr={{nrow,ncol},ntime};
                    q.push(pr);
                    ans=max(ans,ntime);
                    frcnt--;
                    grid[nrow][ncol]=2;
                }
                
            }
            
            
        }
        if(frcnt>0)
        {
            return -1;
        }
        return ans;
 
        
    }
};