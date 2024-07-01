class Solution
{
    public:
        int getans(int amount, vector<int> &coins, int idx, vector<vector<int>> &dp)
        {
            if (coins.size() == idx)
            {
                return amount == 0;
            }
            if(dp[amount][idx]!=-1)
            {
                return dp[amount][idx];
            }
           	//pick
            int pick = 0;
            if (coins[idx] <= amount)
            {
                pick = getans(amount - coins[idx], coins, idx,dp);
            }
           	//notpick
            int notpick = getans(amount, coins, idx + 1,dp);
            return dp[amount][idx]=pick + notpick;
        }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(5001,vector<int> (301,-1));
       return getans(amount, coins, 0,dp);
    }
};