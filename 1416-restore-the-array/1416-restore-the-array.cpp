class Solution
{
    public:
        int numberOfArrays(string s, int k)
        {
            int n = (int) s.size();
            vector<int> dp(n + 1, 0);
            dp[n] = 1;	// the base case
            for (int i = n - 1; i >= 0; --i)
            {
                int num = s[i] - '0', j = i + 1;
                while (num > 0 && num <= k && j < n + 1)
                {
                    dp[i] = (dp[i] + dp[j]) % 1000000007;
                   	// a tiny trick to avoid overflow
                    num = (j < n && num <= k / 10) ? 10 *num + (s[j] - '0') : INT_MAX;
                    j++;
                }
            }
            return dp[0];
        }
};