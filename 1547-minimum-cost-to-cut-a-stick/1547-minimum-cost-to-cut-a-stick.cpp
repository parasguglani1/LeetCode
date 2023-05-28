class Solution {
public:
   int knapsack(int i, int j, vector<int>&c, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long mini = INT_MAX;;
        for(int idx =i;idx<=j;idx++){
            long cost = c[j+1]-c[i-1] + knapsack(i,idx-1,c,dp)  + knapsack(idx+1,j,c,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return knapsack(1,c,cuts,dp);
    }

};