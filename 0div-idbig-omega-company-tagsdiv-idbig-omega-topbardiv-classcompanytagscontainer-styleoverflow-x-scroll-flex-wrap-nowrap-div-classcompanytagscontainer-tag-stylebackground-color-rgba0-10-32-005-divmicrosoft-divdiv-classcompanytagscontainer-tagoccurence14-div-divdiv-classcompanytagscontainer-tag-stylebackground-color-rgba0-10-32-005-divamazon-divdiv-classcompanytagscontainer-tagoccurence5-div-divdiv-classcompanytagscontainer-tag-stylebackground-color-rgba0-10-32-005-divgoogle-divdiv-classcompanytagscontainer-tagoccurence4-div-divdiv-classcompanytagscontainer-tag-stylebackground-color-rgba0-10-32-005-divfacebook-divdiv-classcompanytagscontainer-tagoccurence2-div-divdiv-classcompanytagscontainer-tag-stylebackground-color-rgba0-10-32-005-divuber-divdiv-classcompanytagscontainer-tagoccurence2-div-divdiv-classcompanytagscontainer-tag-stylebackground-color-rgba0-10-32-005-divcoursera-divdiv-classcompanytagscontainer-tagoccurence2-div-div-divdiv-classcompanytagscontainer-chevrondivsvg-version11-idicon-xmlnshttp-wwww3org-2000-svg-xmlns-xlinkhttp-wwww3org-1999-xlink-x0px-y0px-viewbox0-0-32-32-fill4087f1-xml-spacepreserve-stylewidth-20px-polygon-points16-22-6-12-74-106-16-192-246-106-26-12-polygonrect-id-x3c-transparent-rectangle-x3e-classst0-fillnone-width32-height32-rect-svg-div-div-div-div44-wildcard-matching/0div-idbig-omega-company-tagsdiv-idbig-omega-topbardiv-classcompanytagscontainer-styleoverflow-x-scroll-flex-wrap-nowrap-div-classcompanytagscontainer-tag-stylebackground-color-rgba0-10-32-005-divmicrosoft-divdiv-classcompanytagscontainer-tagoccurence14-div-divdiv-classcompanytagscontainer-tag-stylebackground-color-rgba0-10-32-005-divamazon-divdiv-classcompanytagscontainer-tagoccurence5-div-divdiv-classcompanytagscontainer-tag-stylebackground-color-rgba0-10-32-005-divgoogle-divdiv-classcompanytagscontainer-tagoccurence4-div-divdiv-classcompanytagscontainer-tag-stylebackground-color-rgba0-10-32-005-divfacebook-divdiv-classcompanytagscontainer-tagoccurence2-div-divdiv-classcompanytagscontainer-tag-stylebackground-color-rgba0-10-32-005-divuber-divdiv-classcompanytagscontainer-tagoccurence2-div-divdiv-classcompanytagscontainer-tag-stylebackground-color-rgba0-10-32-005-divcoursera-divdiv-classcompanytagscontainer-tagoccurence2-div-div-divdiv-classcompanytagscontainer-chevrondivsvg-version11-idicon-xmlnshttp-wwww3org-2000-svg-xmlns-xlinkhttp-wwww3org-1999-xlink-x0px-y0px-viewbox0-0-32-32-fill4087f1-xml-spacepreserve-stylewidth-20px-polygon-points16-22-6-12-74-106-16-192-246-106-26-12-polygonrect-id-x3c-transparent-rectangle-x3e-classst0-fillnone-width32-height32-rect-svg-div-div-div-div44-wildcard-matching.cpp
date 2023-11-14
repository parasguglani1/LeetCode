class Solution
{
    public:
    //memoization
        bool getans(int i, int j, string &s, string &p, vector<vector < int>> &dp)
        {
            if (j == 0 && i == 0)
            {
                return true;
            }
            if (i > 0 && j== 0)
            {
                return false;
            }
            if (i == 0 && j > 0)
            {
                for (int ind = 1; ind <= j; ind++)
                {
                    if (p[ind-1] != '*')
                        return false;
                }
                return true;
            }
            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }

            if (s[i-1] == p[j-1] || p[j-1] == '?')
            {
                return dp[i][j] = getans(i - 1, j - 1, s, p, dp);
            }
            if (p[j-1] == '*')
            {
                bool possible = false;
                possible |= getans(i - 1, j, s, p, dp);
                possible |= getans(i, j - 1, s, p, dp);
                return dp[i][j] = possible;
            }
            return dp[i][j] = false;
        }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector < int>> dp(n+1, vector<int> (m+1, -1));

        return getans(n , m, s, p, dp);
    }
};