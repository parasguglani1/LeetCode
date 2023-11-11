class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx = n-1; idx >= 0; idx--){

            int b = -p[idx] + dp[idx+1][0];

            int nb = 0 + dp[idx+1][1];

            int s = p[idx] + dp[idx+1][1];

            int ns = 0 + dp[idx+1][0];

            dp[idx][0] = max(s, ns);

            dp[idx][1] = max(b, nb);
        }
        return dp[0][1];
    }
};
