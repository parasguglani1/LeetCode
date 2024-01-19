class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int n = matrix.size(), m = matrix[0].size();
            vector<vector < int>> dp(n,vector<int> (m, INT_MAX));

            for (int j = 0; j < m; j++)
            {
                dp[n - 1][j] = matrix[n - 1][j];
            }

            for (int i = n - 2; i >= 0; i--)
            {
                for (int j = 0; j < m; j++)
                {
                    dp[i][j] = dp[i + 1][j];
                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i + 1][j - 1],dp[i][j]);
                    }
                    if (j < m - 1)
                    {
                        dp[i][j] = min(dp[i + 1][j + 1],dp[i][j]);
                    }
                    dp[i][j] += matrix[i][j];
                }
            }

            int ans = INT_MAX;
            for (int i = 0; i < m; i++)
            {
                ans = min(ans, dp[0][i]);
            }
            return ans;
        }
};