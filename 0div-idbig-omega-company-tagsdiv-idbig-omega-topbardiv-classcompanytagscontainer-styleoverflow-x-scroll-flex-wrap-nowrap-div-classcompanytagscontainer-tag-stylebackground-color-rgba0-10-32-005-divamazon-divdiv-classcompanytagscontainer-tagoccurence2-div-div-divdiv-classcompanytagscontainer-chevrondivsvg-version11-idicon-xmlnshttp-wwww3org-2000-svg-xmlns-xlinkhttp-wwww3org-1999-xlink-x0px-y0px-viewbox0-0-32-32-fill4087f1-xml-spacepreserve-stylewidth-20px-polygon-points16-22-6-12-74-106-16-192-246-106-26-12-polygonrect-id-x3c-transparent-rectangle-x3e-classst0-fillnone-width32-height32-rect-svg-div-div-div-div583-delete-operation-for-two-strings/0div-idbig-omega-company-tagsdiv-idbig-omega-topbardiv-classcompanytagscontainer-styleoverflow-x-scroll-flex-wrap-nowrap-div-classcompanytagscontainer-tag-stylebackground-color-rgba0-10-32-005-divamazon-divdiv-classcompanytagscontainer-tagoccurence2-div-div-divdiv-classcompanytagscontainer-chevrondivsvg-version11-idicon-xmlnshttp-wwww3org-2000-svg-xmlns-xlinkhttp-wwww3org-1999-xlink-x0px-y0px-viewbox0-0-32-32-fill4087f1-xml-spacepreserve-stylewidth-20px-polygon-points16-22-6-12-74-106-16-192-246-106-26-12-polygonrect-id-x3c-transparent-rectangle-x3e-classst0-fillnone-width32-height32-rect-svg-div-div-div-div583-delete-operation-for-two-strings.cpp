class Solution
{
    public:

        int getans(int i, int j, string &word1, string &word2,vector<vector<int>> &dp)
        {
            if(i<0 &&j<0)
            {
                return 0;
            }
            else if(i<0)
            {
                return j+1;
            }
            else if(j<0)
            {
                return i+1;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            if (word1[i] == word2[j])
            {
                return dp[i][j]= getans(i - 1, j - 1, word1, word2,dp);
            }
            else
            {
                int delfrom1 = getans(i - 1, j, word1, word2,dp) + 1;
                int delfrom2 = getans(i, j - 1, word1, word2,dp) + 1;
                return dp[i][j]= min(delfrom1, delfrom2);
            }
        }
    int minDistance(string word1, string word2)
    {
        if(word1==word2)
        {
            return 0;
        }
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return getans(n-1, m-1, word1, word2,dp);
    }
};