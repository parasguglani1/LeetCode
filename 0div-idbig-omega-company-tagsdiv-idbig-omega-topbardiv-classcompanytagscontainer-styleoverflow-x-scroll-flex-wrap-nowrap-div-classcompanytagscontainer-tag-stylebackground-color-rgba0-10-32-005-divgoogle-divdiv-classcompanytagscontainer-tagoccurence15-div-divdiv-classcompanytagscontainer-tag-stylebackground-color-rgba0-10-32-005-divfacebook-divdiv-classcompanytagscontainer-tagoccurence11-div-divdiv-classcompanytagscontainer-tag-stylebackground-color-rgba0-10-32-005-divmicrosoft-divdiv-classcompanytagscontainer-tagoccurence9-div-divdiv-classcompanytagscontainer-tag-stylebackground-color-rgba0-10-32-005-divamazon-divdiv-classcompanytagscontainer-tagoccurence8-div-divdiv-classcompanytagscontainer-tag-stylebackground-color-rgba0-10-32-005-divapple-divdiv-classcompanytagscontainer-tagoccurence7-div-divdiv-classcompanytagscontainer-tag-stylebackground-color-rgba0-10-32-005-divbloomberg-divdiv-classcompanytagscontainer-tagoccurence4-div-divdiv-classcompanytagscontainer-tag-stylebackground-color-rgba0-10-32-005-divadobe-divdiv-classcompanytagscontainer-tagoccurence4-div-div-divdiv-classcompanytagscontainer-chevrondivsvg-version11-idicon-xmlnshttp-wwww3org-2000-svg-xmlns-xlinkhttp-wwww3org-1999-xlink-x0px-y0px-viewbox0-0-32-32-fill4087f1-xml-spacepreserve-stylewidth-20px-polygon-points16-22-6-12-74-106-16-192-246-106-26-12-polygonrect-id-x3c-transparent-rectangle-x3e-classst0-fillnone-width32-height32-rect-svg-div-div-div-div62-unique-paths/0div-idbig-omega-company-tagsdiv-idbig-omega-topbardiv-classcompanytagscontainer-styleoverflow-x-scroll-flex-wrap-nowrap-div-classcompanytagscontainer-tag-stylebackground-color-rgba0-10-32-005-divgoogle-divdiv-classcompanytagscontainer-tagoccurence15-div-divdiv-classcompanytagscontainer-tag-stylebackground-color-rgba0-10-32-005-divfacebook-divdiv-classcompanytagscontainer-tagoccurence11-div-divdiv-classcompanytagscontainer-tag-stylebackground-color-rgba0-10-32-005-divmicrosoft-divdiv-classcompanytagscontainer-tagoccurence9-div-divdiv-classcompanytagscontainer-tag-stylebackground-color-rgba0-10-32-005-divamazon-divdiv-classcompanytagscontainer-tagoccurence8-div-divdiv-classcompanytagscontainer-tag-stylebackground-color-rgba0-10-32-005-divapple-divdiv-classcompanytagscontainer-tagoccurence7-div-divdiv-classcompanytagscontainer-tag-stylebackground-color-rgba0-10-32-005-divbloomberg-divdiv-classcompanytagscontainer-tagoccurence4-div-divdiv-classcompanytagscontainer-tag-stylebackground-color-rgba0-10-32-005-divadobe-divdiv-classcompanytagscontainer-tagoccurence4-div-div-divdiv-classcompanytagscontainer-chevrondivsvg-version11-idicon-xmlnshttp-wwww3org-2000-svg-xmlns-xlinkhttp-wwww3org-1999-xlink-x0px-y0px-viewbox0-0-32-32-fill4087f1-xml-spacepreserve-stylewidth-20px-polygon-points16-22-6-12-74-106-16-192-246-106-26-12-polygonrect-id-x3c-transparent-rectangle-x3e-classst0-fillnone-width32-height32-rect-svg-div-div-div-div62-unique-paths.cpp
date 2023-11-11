class Solution
{
    public:

        int getpath(int m, int n, int i, int j, vector<vector < int>> &dp)
        {
            if (i == n - 1 && j == m - 1)
            {
                return 1;
            }
            if (i >= n || j >= m)
                return 0;
            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }

            int left = getpath(m, n, i + 1, j, dp);
            int down = getpath(m, n, i, j + 1, dp);
            return dp[i][j] = left + down;
        }
    int uniquePaths(int m, int n)
    {
        vector<vector < int>> dp(n + 1, vector<int> (m + 1, 1));

       	// int ans = getpath(m, n, 0, 0, dp);

        // dp[0][0] = 1;

        for (int i = 1; i < n ; i++)
        {
            for (int j = 1; j < m ; j++)
            {
                int left = 0, down = 0;
                // if (j > -1)
                    left = dp[i][j - 1];
                // if (i > -1)
                    down = dp[i - 1][j];

                dp[i][j] = left + down;
            }
        }
       int ans = dp[n - 1][m - 1];

        return ans;
    }
};