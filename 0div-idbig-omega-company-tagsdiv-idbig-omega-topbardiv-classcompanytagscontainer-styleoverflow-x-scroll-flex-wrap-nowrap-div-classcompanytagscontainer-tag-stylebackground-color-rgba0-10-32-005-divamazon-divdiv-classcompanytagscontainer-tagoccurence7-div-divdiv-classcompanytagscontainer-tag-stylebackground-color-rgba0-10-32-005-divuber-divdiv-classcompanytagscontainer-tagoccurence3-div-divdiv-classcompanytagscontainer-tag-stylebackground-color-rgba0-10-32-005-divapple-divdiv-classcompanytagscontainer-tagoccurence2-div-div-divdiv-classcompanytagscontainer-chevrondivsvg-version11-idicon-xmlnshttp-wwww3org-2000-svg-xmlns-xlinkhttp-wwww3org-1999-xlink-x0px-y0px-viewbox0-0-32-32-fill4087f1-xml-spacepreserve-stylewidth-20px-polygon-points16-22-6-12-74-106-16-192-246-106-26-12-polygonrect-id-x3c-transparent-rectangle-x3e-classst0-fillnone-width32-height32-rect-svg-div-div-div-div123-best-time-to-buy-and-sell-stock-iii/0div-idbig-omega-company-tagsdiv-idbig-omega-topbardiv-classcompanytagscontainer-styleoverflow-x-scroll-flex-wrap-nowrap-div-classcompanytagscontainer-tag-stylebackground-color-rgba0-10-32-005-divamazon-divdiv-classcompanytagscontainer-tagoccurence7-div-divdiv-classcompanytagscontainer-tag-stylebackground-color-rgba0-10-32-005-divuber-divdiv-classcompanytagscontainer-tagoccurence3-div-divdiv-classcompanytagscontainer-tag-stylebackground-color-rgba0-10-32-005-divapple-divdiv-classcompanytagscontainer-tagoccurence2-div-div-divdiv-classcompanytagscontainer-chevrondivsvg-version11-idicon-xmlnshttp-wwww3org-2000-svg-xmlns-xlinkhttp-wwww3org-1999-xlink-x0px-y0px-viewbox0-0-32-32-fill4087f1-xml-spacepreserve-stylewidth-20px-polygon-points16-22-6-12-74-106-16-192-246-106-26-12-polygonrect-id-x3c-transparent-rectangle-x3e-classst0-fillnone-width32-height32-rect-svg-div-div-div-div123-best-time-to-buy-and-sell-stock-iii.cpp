class Solution
{
    public:
        int getans(int idx, bool buy, int cap, vector<int> &prices, vector<vector< vector< int>>> &dp)
        {
            int n = prices.size();
            if (idx == n || cap == 0)
                return 0;

            if (dp[idx][buy][cap] != -1)
                return dp[idx][buy][cap];

            int ans = 0;
            if (buy)
            {
                int b = -prices[idx] + getans(idx + 1, 0, cap, prices, dp);
                int nb = 0 + getans(idx + 1, 1, cap, prices, dp);
                ans = max(b, nb);
            }
            else
            {
                int s = prices[idx] + getans(idx + 1, 1, cap - 1, prices, dp);
                int ns = 0 + getans(idx + 1, 0, cap, prices, dp);
                ans = max(s, ns);
            }
            return dp[idx][buy][cap] = ans;
        }
    int maxProfit(vector<int> &prices)
    {
       	// vector<vector < int>> dp(prices.size(), vector<int> (2, -1));

        int n = prices.size();
        int k = 2;
        vector<vector<vector< int>>> dp(n, vector<vector < int>> (2, vector<int> (k + 1, -1)));
        return getans(0, 1, k, prices, dp);
    }
};