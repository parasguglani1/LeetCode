class Solution
{
    public:

        bool ispossible(vector<int> &nums, int target, int ind,vector<vector < int>> &dp)
        {
            if (ind < 0||target<0)
            {
                return false;
            }
            if (nums[ind] == target)
            {
                return true;
            }
            
            if(dp[ind][target]!=-1)
            {
                return dp[ind][target];
            }
           	int n = nums.size();
           	//take
            bool take = ispossible(nums, target - nums[ind], ind - 1,dp);
            // // cout<<target<<endl;
            // //nottake
            bool nottake = ispossible(nums, target, ind - 1,dp);
            // return dp[ind][target]=take | nottake;
            return dp[ind][target]=take|nottake;
            // return true;
        }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
        {
            return false;
        }
        vector<vector < int>> dp(n, vector<int> (sum / 2 + 1, -1));
        // for(int i=0;i<dp.size();i++)
        // {
        //     for(int j=0;j<dp[0].size();j++)
        //     {
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        return ispossible(nums, sum / 2, n - 1,dp);
    }
};