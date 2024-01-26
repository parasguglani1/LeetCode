class Solution
{
    public:
    vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
    

        bool isValid(int &i, int &j, int &n)
        {
            return (i > -1 && i < n && j > -1 && j < n);
        }
    void dfs(int t, vector<vector < int>> &grid,vector<vector<int>> &vis, int i, int j, int n)
    {
        vis[i][j] = 1;
        for (auto x: moves)
        {
            int nx = x.first + i;
            int ny = x.second + j;
            if (isValid(nx, ny, n) && !vis[nx][ny] && grid[nx][ny] <= t)
                {
                    dfs(t, grid, vis,nx, ny, n);
                }
            }
        }
        bool isPossible(int t, vector < vector<int>> &grid, int n)
        {
            vector<vector < int>> vis(n, vector<int> (n, 0));

            dfs(t, grid,vis, 0, 0, n);
            return vis[n - 1][n - 1];
        }
        int swimInWater(vector<vector < int>> &grid)
        {
            int l = grid[0][0];
            int n = grid.size();
            // int r = 0;
            // for (auto x: grid)
            // {
            //     for (auto y: x)
            //     {
            //         r = max(r, y);
            //     }
            // }
            
for(int i=l;i<n*n;i++)
{
    if(isPossible(i,grid,n))
    {
        return i;
    }
}
            return 0;
//             while (l < r)
//             {
                
//                     // cout<<l<<' '<<r<<endl;
//                 int mid = (l + r) / 2;
//                     // cout<<mid<<endl;

//                 if (isPossible(mid, grid, n))
//                 {
//                     // cout<<mid<<endl;
//                     r = mid;
//                 }
//                 else
//                 {
//                     // cout<<mid<<endl;
                    
//                     l = mid + 1;
//                 }
//             }
//             return l;
        }
    };