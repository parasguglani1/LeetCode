class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=grid[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int x=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                    {
                        x=min(x,dp[i+1][k]);
                    }
                    
                }
                dp[i][j]=x+grid[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};