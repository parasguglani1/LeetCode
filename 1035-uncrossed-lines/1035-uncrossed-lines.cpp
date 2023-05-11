class Solution
{
    public:
        int rec(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int i , int j){
            if(i < 0 || j < 0)
                  return 0;
            if(dp[i][j] != -1)
                 return dp[i][j];
            int take = -1;
            for(int k = j; k >= 0; k--){
                if(nums1[i] == nums2[k]){
                    take = max(take, rec(nums1, nums2, dp, i - 1, k - 1));
                }
            }
            int notTake = rec(nums1, nums2, dp, i - 1, j);
            return dp[i][j] = max(take +  1, notTake);
        }
        int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
            int n =  nums1.size(), m = nums2.size();
            vector<vector<int>> dp(n, vector<int>(m, 0));
            // int ans = rec(nums1, nums2, dp, n - 1, m - 1);
            // for(auto it: dp){
            //     for(auto itr: it)
            //           cout << itr << " ";
            //     cout << '\n';
            // }
            if(nums1[0] == nums2[0])
                  dp[0][0] = 1;
            for(int i = 1; i < m; i++){
                if(nums2[i] == nums1[0])
                   dp[0][i] = 1;
                 else
                    dp[0][i] = max(0, dp[0][i - 1]);
            }
            for(int i = 1; i < n; i++){
                if(nums1[i] == nums2[0])
                   dp[i][0] = 1;
                 else
                    dp[i][0] = max(0, dp[i - 1][0]);
            }
            for(int i = 1; i < n; i++){
                for(int j = 1; j < m; j++){
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    if(nums1[i] == nums2[j]){
                        dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                    }
                }
            }
            return dp[n - 1][m - 1];
        }
};