class Solution
{
    public:
        void dfs(vector<vector < int>> &grid, int row, int col, int stc, int color, vector< vector< int>> &vis)
        {
            int n = grid.size();
            int m = grid[0].size();
            grid[row][col] = color;
            vis[row][col] = 1;
             int delrow[4]={0,0,-1,1};
            int delcol[4]={-1,1,0,0};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == stc && !vis[nrow][ncol])
                {
                    dfs(grid, nrow, ncol, stc, color, vis);
                }
            }
        }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        int stc = image[sr][sc];
        if (stc == color)
        {
            return image;
        }
        vector<vector < int>> grid = image;
        vector<vector < int>> vis(n, vector<int> (m, 0));

        dfs(grid, sr, sc, stc, color, vis);
        return grid;
    }
};