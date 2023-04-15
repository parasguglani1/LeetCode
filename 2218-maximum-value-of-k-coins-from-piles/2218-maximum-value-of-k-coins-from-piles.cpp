class Solution
{
    public:
        int maxValueOfCoins(vector<vector < int>> &p, int k)
        {
            vector<int> dp(k + 1, 0);
            for (int j = 1; j < dp.size(); j++)
                dp[j] = dp[j - 1] + (j <= p.back().size() ? p.back()[j - 1] : 0);

            for (int i = p.size() - 2; i >= 0; i--)
            {
                vector<int> ndp(k + 1, 0);
                vector<int> pre
                { 0 };
                for (auto n: p[i]) pre.emplace_back(pre.back() + n);
                for (int m = 0; m < pre.size(); m++)
                    for (int j = 0; j + m < dp.size(); j++)
                        ndp[m + j] = max(ndp[m + j], pre[m] + dp[j]);
                dp = ndp;
            }
            return dp.back();
        }
};