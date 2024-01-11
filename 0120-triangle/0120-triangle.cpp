class Solution
{
    public:
        int getans(vector<vector < int>> &triangle, int i, int j,vector<vector<int>> &dp)
        {
            if (j == triangle.size()-1)
            {
                // return -1;
                return dp[j][i]=triangle[j][i];
            }
            if(dp[j][i]!=-1)
            {
                return dp[j][i];
            }
            int leftans = getans(triangle, i, j + 1,dp);
            int rightans = getans(triangle, i + 1, j + 1,dp);
            return dp[j][i]=min(leftans, rightans)+triangle[j][i];
        }
    int minimumTotal(vector<vector < int>> &triangle)
    {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getans(triangle, 0, 0,dp);
    }
};