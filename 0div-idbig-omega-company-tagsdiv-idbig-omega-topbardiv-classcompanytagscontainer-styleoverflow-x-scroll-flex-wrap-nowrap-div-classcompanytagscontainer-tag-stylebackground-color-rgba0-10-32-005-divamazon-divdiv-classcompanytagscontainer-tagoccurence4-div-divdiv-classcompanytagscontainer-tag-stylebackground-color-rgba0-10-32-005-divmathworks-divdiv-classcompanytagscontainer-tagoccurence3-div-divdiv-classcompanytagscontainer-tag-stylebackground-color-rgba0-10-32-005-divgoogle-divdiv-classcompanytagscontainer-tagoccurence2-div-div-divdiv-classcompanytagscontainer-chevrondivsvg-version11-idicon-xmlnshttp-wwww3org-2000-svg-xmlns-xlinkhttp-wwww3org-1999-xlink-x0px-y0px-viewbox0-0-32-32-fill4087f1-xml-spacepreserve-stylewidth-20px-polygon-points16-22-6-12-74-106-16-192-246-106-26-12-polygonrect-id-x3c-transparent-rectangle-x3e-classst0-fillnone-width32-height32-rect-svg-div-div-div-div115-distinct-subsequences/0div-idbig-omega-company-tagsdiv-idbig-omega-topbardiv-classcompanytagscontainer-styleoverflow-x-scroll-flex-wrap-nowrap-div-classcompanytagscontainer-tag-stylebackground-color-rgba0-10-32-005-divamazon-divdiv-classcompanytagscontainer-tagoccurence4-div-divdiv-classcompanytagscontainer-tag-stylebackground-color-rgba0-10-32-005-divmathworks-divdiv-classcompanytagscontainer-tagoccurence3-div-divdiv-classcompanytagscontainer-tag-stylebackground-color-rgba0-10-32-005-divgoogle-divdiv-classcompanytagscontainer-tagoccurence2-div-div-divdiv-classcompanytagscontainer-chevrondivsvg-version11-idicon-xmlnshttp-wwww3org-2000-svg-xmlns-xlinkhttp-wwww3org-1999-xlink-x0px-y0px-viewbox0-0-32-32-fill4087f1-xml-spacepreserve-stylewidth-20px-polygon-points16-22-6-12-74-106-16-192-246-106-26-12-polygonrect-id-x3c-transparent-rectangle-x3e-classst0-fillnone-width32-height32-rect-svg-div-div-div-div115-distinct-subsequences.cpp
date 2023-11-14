class Solution
{
    public:
       	//tabulation
        int numDistinct(string s, string t)
        {

            int n = s.size();
            int m = t.size();
            vector<vector < long long>> dp(n + 1, vector < long long > (m + 1, 0));
            for (int j = 0; j <= n; j++)
            {
                dp[j][0] = 1;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    int nottaken = dp[i - 1][j];
                    int taken = 0;

                    if (s[i - 1] == t[j - 1])
                    {
                        taken = dp[i - 1][j - 1];
                    }

                    dp[i][j] = (long) taken + nottaken;
                }
            }

            int ans = dp[n][m];
            return ans;
        }
};