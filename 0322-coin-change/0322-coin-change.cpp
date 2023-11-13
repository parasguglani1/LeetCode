class Solution {
public:
    int getans(vector<int> &coins,int ind, long long target,vector<vector<long long>> &dp)
    {
        // if(target<0)
        // {
        //     return 0;
        // }
        //base
        if(ind==0)
        {
            if (target%coins[0]==0)
            return target/coins[0];
            return 1e9;
        }
        
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        
        long long take=INT_MAX;
        if(target>=coins[ind]) take= 1+getans(coins,ind,target-coins[ind],dp);
        long long nottake= getans(coins,ind-1,target,dp);
        long long curans=min(take,nottake);
        return dp[ind][target]=curans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<long long>> dp(n,vector<long long> (amount+1,-1));
        int ans=getans(coins,n-1,amount,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};