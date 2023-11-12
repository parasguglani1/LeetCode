class Solution
{
    public:

//         int getans(int i, int j, vector<vector < int>> &grid, vector< vector< int>> &dp)
//         {
//             if (i == 0 && j == 0) return grid[i][j];

//             if (i < 0 || j < 0) return 1e9;
//             if (dp[i][j] != -1)
//             {
//                 return dp[i][j];
//             }
//             int up = getans(i - 1, j, grid, dp);
//             int left = getans(i, j - 1, grid, dp);

//             return dp[i][j] = min(up, left) + grid[i][j];
//         }
    int minPathSum(vector<vector < int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        // vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));

        vector<int> curr(m),prev(m);
        // dp[0][0]=grid[0][0];
        prev[0]=curr[0]=grid[0][0];
        // for (int i = 1; i < m; i++)
        // {
        //     dp[0][i] = grid[0][i]+dp[0][i-1];
        // }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(i==0 &&j==0)
                {
                    continue;
                }
                int left = 1e9;
                int up = 1e9;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
            curr[j] = min(left, up) + grid[i][j];
                // cout<<dp[i][j]<<' ';
            }
            prev=curr;
            // cout<<endl;
        }

        return curr[m-1];
    }
};