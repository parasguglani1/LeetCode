class Solution {
public:
    int mod = 1e9+7;
    int helper(int idx, int zero, int one, vector<int> &dp)
    {
		//base case
        if(idx == 0)
        {
            return 1;
        }
        if(idx < 0)
        {
            return 0;
        }
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        return dp[idx] =(helper(idx - zero, zero, one, dp) % mod + helper(idx - one, zero, one, dp) % mod) % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for(int i = low; i <= high; i++)
        {
            ans = (ans + helper(i, zero, one, dp) % mod) % mod;
        }
        return ans;
    }
};
