class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m=heights.size(),n=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0,0});//eff,row,col
        while(!q.empty())
        {
            vector<int> v=q.top();
            q.pop();
            int eff=v[0],x=v[1],y=v[2];
            if(x==m-1&&y==n-1)
                return eff;
            if(x<0||y<0||x>=m||y>=n||heights[x][y]==0)
                continue;
            for(int i=0;i<4;i++)
            {
                int nx=x+dir[i],ny=y+dir[i+1];
                if(nx <= m-1 && ny <= n-1 && nx >=0 && ny>=0)
                q.push({max(eff,abs(heights[x][y]-heights[nx][ny])),nx,ny});
                
            }
            heights[x][y]=0;
            
        }
        
        return 0;
    }
};
