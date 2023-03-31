class Solution
{
    public:
        int dp[51][51][11];
    int ways(vector<string> &p, int k)
    {
        memset(dp, -1, sizeof(dp));
        return recur(p, k, 0, 0);
    }
    int recur(vector<string> &p, int k, int i, int j)
    {
        if (dp[i][j][k] != -1) return dp[i][j][k];
        if (k == 1)
            return check(p, i, j, p.size() - 1, p[0].size() - 1);
        int ret = 0;
        int idx = i;
        for (idx = i; idx < p.size(); idx++)
            if (check(p, i, j, idx, p[0].size() - 1)) break;
        for (; idx < p.size(); idx++)
            ret = (ret + recur(p, k - 1, idx + 1, j)) % 1000000007;
        for (idx = j; idx < p[0].size(); idx++)
            if (check(p, i, j, p.size() - 1, idx)) break;
        for (; idx < p[0].size(); idx++)
            ret = (ret + recur(p, k - 1, i, idx + 1)) % 1000000007;
        return dp[i][j][k] = ret;
    }
    bool check(vector<string> &p, int I, int J, int i, int j)
    {
        for (int r = I; r <= i; r++)
            for (int c = J; c <= j; c++)
                if (p[r][c] == 'A') return 1;
        return 0;
    }
};