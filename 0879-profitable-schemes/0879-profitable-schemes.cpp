class Solution
{
    public:
        int dp[110][110][110];
    int mod = 1e9 + 7;
    int f(int i, int p, int selected, int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        if (i == group.size())
        {
            if (p >= minProfit && n >= selected) return 1;
            return 0;
        }
        if (n < selected) return 0;
        if (dp[i][p][selected] != -1) return dp[i][p][selected];
        int take = f(i + 1, min(p + profit[i], minProfit), selected + group[i], n, minProfit, group, profit) % mod;
        int dont = f(i + 1, p, selected, n, minProfit, group, profit) % mod;
        return dp[i][p][selected] = (take + dont) % mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, n, minProfit, group, profit);
    }
};