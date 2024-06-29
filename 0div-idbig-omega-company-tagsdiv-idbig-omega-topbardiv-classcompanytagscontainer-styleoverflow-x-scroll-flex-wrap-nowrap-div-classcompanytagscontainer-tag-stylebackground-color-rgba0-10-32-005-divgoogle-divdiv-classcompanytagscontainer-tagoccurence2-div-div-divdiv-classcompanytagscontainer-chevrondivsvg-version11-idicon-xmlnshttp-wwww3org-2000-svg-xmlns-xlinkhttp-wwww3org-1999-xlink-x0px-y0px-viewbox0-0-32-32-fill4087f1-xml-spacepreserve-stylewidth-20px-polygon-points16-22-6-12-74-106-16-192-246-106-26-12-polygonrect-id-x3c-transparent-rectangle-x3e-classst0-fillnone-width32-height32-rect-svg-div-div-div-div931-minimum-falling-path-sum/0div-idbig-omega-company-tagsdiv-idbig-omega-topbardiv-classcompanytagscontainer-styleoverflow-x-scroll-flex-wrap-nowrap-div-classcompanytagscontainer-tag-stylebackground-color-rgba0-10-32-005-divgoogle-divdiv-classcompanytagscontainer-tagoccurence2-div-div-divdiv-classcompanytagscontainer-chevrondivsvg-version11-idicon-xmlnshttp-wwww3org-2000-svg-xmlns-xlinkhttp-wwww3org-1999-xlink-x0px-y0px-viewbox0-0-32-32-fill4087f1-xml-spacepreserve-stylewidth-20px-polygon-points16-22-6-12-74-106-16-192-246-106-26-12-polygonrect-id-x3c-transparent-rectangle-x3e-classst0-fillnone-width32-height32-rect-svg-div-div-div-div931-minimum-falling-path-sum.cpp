class Solution
{
    public:
        int solve(int i, int j, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
            if (j < 0 || j >= matrix[0].size()) return INT_MAX;
            if (i == 0) return matrix[0][j];
            if (dp[i][j] != INT_MAX) return dp[i][j];
            int up =  solve(i - 1, j, matrix, dp);
            int leftdown = solve(i - 1, j - 1, matrix, dp);
            int rightdown =  solve(i - 1, j + 1, matrix, dp);
            return dp[i][j]= min(up, min(leftdown, rightdown))+matrix[i][j];
        }
    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector < int>> dp(n, vector<int> (m, INT_MAX));
        int mn = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            mn = min(mn, solve(n - 1, j, matrix, dp));
        }
        return mn;
    }
};