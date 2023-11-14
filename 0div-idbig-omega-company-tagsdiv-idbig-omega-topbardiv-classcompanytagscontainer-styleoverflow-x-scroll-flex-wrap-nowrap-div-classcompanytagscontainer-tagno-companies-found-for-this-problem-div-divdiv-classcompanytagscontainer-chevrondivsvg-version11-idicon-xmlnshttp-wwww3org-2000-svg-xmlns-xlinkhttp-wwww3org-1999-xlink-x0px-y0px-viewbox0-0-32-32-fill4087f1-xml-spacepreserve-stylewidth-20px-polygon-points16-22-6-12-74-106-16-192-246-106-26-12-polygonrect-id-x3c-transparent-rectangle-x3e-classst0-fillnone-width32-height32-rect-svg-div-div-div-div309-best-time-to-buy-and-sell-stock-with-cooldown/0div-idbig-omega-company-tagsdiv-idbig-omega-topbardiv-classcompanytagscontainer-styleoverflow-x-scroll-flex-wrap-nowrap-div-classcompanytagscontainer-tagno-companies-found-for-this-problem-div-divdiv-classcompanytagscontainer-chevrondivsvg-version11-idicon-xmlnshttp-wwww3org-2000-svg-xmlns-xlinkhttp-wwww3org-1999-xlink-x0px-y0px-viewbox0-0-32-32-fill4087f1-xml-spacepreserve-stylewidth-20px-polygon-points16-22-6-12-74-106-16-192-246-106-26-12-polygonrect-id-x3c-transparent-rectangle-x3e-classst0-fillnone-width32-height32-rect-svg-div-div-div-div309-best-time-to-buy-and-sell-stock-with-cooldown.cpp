class Solution
{
    public:
        int getans(int idx, bool buy, vector<int> &prices, vector<vector< int>> &dp)
        {
            int n = prices.size();
            if (idx >= n)
                return 0;

            if (dp[idx][buy] != -1)
                return dp[idx][buy];

            int ans = 0;
            if (buy)
            {
                int b = -prices[idx] + getans(idx + 1, 0, prices, dp);
                int nb = 0 + getans(idx + 1, 1, prices, dp);
                ans = max(b, nb);
            }
            else
            {
                int s = prices[idx] + getans(idx + 2, 1, prices, dp);
                int ns = 0 + getans(idx + 1, 0, prices, dp);
                ans = max(s, ns);
            }
            return dp[idx][buy] = ans;
        }
    int maxProfit(vector<int> &prices)
    {
        vector<vector < int>> dp(prices.size(), vector<int> (2, -1));
        return getans(0, 1, prices, dp);
    }
};