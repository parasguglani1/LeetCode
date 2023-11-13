class Solution
{
    public:
        int getans(vector<int> &coins, int ind, int target, vector<vector< int>> &dp)
        {

           	//base
            if (ind == 0)
            {
                if (target % coins[0] == 0)
                    return target / coins[0];
                return 1e9;
            }

            if (dp[ind][target] != -1)
            {
                return dp[ind][target];
            }

            int take = INT_MAX;
            if (target >= coins[ind]) take = 1 + getans(coins, ind, target - coins[ind], dp);
            int nottake = getans(coins, ind - 1, target, dp);
            int curans = min(take, nottake);
            return dp[ind][target] = curans;
        }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector < int>> dp(n, vector<int> (amount + 1, 0));
       	// int ans = getans(coins, n - 1, amount, dp);

        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0]==0)
            {
                dp[0][target] = target / coins[0];
            }
            else
            {
                dp[0][target] = 1e9;
            }
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0 ; target <= amount; target++)
            {
                int take = INT_MAX;
                if (target >= coins[ind]) take = 1 + dp[ind][target - coins[ind]];
                int nottake = dp[ind - 1][target];
                dp[ind][target] = min(take, nottake);
            }
        }

       int ans = dp[n - 1][amount];
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};