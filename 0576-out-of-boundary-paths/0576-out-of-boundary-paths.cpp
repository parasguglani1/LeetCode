class Solution {
    int mod = 1e9+7;
    int dfs(int r, int c, int m, int n, int move, vector<vector<vector<int>>>& dp){
        if(r<0 || c<0 || r>=m || c>= n) return 1;
        if(dp[move][r][c] != -1) return dp[move][r][c];

        int ans = dfs(r-1, c, m, n, move-1, dp);
        ans = (ans + dfs(r+1, c, m, n, move-1, dp))%mod;
        ans = (ans + dfs(r, c+1, m, n, move-1, dp))%mod;
        ans = (ans + dfs(r, c-1, m, n, move-1, dp))%mod;
        return dp[move][r][c] = ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n, -1)));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[0][i][j] = 0;
            }
        }
        return dfs(startRow, startColumn, m, n, maxMove, dp);
    }
};
