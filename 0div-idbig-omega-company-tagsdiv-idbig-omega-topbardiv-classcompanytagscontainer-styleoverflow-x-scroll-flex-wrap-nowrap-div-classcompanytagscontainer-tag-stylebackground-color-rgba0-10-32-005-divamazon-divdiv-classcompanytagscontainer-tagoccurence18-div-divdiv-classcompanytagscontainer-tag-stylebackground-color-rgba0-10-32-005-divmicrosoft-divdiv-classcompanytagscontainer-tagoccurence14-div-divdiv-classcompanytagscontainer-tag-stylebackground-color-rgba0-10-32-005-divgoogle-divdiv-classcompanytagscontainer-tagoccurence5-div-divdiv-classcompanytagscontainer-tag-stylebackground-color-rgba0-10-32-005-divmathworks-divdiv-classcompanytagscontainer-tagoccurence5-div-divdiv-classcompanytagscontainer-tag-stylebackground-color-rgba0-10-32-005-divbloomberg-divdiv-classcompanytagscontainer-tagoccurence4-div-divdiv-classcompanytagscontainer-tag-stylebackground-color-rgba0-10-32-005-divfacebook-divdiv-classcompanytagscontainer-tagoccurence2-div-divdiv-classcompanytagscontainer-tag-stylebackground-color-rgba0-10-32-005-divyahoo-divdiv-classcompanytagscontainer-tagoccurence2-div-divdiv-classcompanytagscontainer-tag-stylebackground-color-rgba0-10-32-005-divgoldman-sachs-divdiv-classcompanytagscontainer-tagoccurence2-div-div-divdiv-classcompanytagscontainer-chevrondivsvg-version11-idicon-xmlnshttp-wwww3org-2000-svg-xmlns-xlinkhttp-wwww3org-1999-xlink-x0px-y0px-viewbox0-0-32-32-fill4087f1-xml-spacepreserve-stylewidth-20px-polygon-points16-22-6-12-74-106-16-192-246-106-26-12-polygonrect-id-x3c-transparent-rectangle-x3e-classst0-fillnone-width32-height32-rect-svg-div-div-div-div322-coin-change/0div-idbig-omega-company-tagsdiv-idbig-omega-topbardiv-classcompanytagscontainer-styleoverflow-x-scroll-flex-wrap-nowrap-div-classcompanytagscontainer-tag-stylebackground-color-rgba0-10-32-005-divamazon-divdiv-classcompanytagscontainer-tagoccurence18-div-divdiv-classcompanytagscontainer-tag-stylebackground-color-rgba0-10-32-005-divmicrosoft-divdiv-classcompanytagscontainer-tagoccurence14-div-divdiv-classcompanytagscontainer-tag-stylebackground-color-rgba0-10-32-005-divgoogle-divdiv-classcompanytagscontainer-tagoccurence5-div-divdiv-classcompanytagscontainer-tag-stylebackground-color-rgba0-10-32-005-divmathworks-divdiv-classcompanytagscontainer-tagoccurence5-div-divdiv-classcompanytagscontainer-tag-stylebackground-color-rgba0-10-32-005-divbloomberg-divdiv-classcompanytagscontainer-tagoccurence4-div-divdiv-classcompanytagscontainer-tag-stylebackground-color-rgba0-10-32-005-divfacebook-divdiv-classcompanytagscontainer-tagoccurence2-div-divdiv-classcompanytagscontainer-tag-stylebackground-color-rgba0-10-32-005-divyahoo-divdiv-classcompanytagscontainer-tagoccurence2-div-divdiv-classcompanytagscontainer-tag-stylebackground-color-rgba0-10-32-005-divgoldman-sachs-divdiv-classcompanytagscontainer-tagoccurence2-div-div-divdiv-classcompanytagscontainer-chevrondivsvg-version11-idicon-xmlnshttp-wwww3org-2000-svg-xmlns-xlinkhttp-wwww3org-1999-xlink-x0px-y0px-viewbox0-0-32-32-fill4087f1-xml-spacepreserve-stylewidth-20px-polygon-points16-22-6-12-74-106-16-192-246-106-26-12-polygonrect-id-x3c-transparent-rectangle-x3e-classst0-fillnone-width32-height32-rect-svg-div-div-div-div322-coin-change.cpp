class Solution
{
    public:
       	//space optimization
        int coinChange(vector<int> &coins, int amount)
        {
            int n = coins.size();

           	// vector<vector < int>> dp(n, vector<int> (amount + 1, 0));
            vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
            for (int target = 0; target <= amount; target++)
            {
                if (target % coins[0] == 0)
                {
                    prev[target] = target / coins[0];
                }
                else
                {
                    prev[target] = 1e9;

                }
            }

            for (int ind = 1; ind < n; ind++)
            {
                
                for (int target = 0; target <= amount; target++)
                {
                    int take = 1e9;
                    if (target >= coins[ind])
                    {
                        take = 1 + curr[target - coins[ind]];
                    }
                    int nottake = prev[target];
                    curr[target] = min(take, nottake);
                }
                prev = curr;
            }

            int ans = prev[amount];
            if (ans >= 1e9)
            {
                return -1;
            }
            return ans;
        }
};