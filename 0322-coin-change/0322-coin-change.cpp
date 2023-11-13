class Solution {
public:
    int getans(vector<int> &coins,int ind, int target,vector<vector<int>> &dp)
    {
    
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
        
        int take=INT_MAX;
        if(target>=coins[ind]) take= 1+getans(coins,ind,target-coins[ind],dp);
        int nottake= getans(coins,ind-1,target,dp);
        int curans=min(take,nottake);
        return dp[ind][target]=curans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=getans(coins,n-1,amount,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};