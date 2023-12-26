class Solution
{
    public:
        int mod = 1e9 + 7;

#define ll long long
   	//recursive
    int getans(int n, int k, int target, vector<vector < int>> &dp)
    {
        if (target < 0 || n < 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
       	if(dp[n][target]!=-1)
        {
            // cout<<'h';
           	return dp[n][target];
        }
        ll sum = 0;
        for (int i = 1; i <= k; i++)
        {

            ll temp = getans(n - 1, k, target - i, dp);
            temp %= mod;
            sum += temp;
            sum %= mod;
        }
       	return dp[n][target]=sum;
        
        // return sum;
    }
    int numRollsToTarget(int n, int k, int target)
    {
       	// vector<vector < int>>dp;
        vector<vector < int>> dp(n + 1, vector<int> (target + 1, -1));
        return getans(n, k, target, dp);
       	// vector<int> a(n,1)
    }
};