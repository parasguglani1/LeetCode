class Solution
{
    public:

        int getans(int i, int &k, string &s, char last, vector<vector < int>> &dp)
        {
            if (i >= s.size())
            {
                return 0;
            }
            if (dp[i][last-'a'] != -1)
            {
                return dp[i][last-'a'];
            }

            int take = 0;
            int notTake = 0;
            if (abs(s[i] - last) <= k || last == '{')
            {
                take = 1 + getans(i + 1, k, s, s[i],dp);
            }
            int nottake = getans(i + 1, k, s, last,dp);
            return dp[i][last-'a'] = max(take, nottake);
        }
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        vector<vector < int>> dp(n + 1, vector<int> (28, -1));

        return getans(0, k, s, '{',dp);
    }
};