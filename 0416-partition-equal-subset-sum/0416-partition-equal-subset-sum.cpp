class Solution
{
    public:

        bool ispossible(vector<int> &nums, int target, int ind, vector<vector< int>> &dp)
        {
            if (ind < 0 || target < 0)
            {
                return false;
            }
            if (nums[ind] == target)
            {
                return true;
            }

            if (dp[ind][target] != -1)
            {
                return dp[ind][target];
            }
            int n = nums.size();
           	//take
            bool take = ispossible(nums, target - nums[ind], ind - 1, dp);

            bool nottake = ispossible(nums, target, ind - 1, dp);
            return dp[ind][target] = take | nottake;
        }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
        {
            return false;
        }
        int k = sum / 2;
       	// vector<vector < int>> dp(n, vector<int> (target + 1, -1));

        vector<vector < int>> dp(n, vector<int> (k + 1, 0));

        vector<int> curr(k + 1), prev(k + 1);
       	//tabulation

        prev[0] = 1;
        if (nums[0] <= k)
            prev[nums[0]] = 1;
        for (int ind = 1; ind < n; ind++)
        {
           	// cout<<nums[ind]<<' ';
            for (int target = 1; target <= k; target++)
            {
                bool nottake = prev[target];
               	// cout<<nottake<<endl;
                bool take = 0;
                if (target >= nums[ind])
                    take = prev[target - nums[ind]];
                curr[target] = take | nottake;
            }
            prev = curr;
        }
        return prev[k];
       	// for(int i=0;i < dp.size();i++)
       	// {
       	//     for(int j=0;j < dp[0].size();j++)
       	//     {
       	//         cout<<dp[i][j]<<' ';
       	//     }
       	//     cout<<endl;
       	// }
       	// return ispossible(nums, sum / 2, n - 1, dp);
    }
};