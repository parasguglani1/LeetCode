class Solution
{
    public:
vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int i, int j, int n, int m)
{
    return (i>-1 &&i<n &&j>-1 &&j<m);
}
    void dfs(vector<vector<int>> &visited,vector<vector<int>> grid,int i,int j,int n,int m, int &count)
    {
        visited[i][j]=1;
        count+=grid[i][j];
            
            for(auto x:moves)
            {
                int nx=x.first+i;
                int ny=x.second+j;
                if(isValid(nx,ny,n,m) &&!visited[nx][ny] &&grid[nx][ny])
                {
                    dfs(visited,grid,nx,ny,n,m,count);
                }
            }
        
    }
        int maxAreaOfIsland(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            int ans = 0;
            vector<vector < int>> visited(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] && !visited[i][j])
                    {
                        int count = 0;
                        dfs(visited, grid, i, j, n, m, count);
                        ans = max(ans, count);
                    }
                }
            }
            return ans;
        }
};