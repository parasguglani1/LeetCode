class Solution
{
    public:
        int change(int amount, vector<int> &coins)
        {
            int n = coins.size();
            vector<int> prev(amount + 1, 0), curr(amount + 1, 0);            
            for (int target = 0; target <= amount; target++)
            {
                if (target % coins[0] == 0)
                {
                    prev[target] = 1;
                }
            }
            for (int ind = 1; ind < n; ind++)
            {
                for (int target = 0; target <= amount; target++)
                {
                    int take = 0;
                    if (target >= coins[ind])
                    {
                        take = curr[target - coins[ind]];
                    }
                    int nottake = prev[target];
                    curr[target] = take+ nottake;
                }
                prev = curr;
            }

            int ans = prev[amount];
            return ans;
        }
};