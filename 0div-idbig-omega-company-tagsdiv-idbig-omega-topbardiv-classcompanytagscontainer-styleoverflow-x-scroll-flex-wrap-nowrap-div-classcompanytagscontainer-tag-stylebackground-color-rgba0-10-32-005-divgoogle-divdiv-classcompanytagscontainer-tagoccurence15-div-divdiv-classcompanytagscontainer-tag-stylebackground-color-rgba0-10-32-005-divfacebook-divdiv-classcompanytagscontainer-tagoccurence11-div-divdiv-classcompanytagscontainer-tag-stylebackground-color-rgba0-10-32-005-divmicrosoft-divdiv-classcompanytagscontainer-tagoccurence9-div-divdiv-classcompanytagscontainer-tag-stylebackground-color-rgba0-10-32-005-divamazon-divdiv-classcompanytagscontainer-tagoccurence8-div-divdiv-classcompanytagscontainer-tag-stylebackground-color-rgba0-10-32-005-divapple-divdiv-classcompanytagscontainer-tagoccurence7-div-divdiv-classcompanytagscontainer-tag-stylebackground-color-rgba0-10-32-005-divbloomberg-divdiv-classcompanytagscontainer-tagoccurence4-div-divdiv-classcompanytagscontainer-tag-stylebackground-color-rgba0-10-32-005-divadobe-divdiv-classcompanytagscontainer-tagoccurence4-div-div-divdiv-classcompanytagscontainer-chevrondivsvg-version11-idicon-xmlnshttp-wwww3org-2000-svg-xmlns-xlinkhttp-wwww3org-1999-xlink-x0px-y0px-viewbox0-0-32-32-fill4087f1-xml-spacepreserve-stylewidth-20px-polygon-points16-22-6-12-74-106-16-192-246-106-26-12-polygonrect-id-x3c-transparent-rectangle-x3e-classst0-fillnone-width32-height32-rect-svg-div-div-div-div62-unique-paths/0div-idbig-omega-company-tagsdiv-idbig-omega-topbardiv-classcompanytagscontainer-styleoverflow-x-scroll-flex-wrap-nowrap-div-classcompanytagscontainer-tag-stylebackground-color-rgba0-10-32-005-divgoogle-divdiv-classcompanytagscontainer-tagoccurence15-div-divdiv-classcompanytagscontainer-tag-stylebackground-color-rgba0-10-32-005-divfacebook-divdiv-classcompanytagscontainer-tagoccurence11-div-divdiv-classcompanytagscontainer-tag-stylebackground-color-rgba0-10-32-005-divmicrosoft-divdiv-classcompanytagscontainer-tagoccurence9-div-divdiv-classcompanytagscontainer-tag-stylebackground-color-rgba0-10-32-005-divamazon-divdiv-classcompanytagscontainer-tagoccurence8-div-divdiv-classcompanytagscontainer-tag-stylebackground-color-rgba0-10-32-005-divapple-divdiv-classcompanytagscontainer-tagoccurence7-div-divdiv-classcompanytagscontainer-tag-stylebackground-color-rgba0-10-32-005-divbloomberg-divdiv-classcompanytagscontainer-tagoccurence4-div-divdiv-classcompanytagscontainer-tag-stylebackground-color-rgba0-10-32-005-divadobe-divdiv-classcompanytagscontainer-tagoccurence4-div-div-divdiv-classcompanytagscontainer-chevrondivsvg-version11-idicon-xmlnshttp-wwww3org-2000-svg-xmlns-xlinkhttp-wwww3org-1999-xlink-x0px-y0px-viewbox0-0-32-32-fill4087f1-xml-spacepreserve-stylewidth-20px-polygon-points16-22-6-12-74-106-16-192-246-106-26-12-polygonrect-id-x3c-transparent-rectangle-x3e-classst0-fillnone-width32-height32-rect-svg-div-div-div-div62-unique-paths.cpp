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
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;

    }
};