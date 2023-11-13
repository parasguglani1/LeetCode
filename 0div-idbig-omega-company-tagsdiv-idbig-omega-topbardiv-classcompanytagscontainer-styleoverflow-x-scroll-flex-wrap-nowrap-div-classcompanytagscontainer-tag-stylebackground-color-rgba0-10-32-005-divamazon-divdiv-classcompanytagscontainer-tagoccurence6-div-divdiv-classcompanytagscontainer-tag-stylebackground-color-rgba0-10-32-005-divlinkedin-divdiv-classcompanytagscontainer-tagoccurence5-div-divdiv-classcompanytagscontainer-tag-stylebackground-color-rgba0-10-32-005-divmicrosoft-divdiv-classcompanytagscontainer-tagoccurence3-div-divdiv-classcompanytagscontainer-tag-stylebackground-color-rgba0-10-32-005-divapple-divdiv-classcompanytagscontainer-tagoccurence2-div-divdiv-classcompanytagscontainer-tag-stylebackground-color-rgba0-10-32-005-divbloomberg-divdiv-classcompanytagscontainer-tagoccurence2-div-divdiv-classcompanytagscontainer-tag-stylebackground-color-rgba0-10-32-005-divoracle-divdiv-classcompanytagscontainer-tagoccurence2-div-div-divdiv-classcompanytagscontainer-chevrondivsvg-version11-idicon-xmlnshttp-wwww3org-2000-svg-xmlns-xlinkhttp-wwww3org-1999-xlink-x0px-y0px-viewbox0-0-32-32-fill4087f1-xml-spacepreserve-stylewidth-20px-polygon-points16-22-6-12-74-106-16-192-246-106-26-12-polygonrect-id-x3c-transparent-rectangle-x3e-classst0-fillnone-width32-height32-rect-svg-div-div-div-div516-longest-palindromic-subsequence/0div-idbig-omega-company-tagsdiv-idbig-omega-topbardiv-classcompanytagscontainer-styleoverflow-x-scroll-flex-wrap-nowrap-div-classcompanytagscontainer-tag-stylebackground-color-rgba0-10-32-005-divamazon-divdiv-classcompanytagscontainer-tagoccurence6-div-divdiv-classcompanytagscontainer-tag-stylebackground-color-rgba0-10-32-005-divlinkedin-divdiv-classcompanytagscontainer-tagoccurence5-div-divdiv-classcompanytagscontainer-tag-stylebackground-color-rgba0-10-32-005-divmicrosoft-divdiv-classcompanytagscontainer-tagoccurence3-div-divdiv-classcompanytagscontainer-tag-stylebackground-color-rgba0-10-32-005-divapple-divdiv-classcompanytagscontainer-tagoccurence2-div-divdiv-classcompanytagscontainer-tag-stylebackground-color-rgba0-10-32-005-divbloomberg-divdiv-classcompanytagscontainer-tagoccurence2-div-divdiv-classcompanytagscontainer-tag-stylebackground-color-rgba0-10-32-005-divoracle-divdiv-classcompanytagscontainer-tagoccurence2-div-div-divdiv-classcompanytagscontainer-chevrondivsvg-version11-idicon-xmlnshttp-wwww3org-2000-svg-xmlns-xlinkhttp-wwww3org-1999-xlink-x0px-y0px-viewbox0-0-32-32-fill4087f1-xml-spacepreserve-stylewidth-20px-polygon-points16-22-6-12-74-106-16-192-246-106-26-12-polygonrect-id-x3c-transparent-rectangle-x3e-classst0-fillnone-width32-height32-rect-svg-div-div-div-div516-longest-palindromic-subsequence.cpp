class Solution {
public:
    int getlcs(int i, int j, string &text1, string &text2, vector<vector < int>> &dp)
        {
            if (i < 0 || j < 0)
            {
                return 0;
            }
            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + getlcs(i - 1, j - 1, text1, text2, dp);
            }
            else
            {
                ans = max(getlcs(i - 1, j, text1, text2, dp), getlcs(i, j - 1, text1, text2, dp));
            }
            return dp[i][j] = ans;
        }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector < int>> dp(n, vector<int> (m, -1));
        int ans = getlcs(n - 1, m - 1, text1, text2,dp);
        return ans;
    }
    int longestPalindromeSubseq(string s) {
     
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};