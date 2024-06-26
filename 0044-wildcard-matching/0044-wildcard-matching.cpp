class Solution
{
    public:
       	//tabulation
        bool isMatch(string s, string p)
        {
            int n = s.size();
            int m = p.size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
            dp[0][0] = 1;

            bool flag = true;

            for (int j = 1; j <= m; j++)
            {

                if (p[j - 1] != '*')
                {
                    flag = false;
                    break;
                }
                dp[0][j] = flag;
            }
            // for(int j=0;j<=m;j++)
            // {
            //     cout<<dp[0][j]<<' ';
            // }
            // cout<<endl;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else if (p[j - 1] == '*')
                    {
                        bool possible = false;
                        possible |= dp[i - 1][j];
                        possible |= dp[i][j - 1];
                        dp[i][j] = possible;
                    }
                    else dp[i][j] = false;
                    // cout<<dp[i][j]<<' ';
                }
                // cout<<endl;
            }

            return dp[n][m];
        }
};