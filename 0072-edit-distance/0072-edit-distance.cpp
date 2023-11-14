class Solution
{
    public:
       	//tabulation
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i ;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j ;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int same = 0, insert = 1e9, replace = 0, chardelete = 1e9;
                same = dp[i - 1][j - 1];
               	// return same;
                replace = same;
                if (word1[i-1] != word2[j-1])
                {
                   	//insert
                    insert = dp[i][j-1] + 1;;

                    replace++;
                   	//delete
                    chardelete = dp[i - 1][j] + 1;
                }
                dp[i][j] = min({ insert,
                    replace,
                    chardelete });
            }
        }

        int ans = dp[n][m];
       	// int ans = getans(n1-1, n2-1, word1, word2,dp);
        return ans;
    }
};