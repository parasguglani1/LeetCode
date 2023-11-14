class Solution
{
    public:
    //memoization
        int getans(int i, int j, string &word1, string &word2,vector<vector<int>>&dp)
        {
            if(i<0)
            {
                return j+1;
            }
            if(j<0)
            {
                return i+1;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int same = 0, insert = 1e9, replace = 0, chardelete = 1e9;
            same = getans(i - 1, j - 1, word1, word2,dp);
            // return same;
            replace = same;
            if (word1[i] != word2[j])
            {
               	//insert
                insert = getans(i, j - 1, word1, word2,dp) + 1;;
                    
                replace++;
               	//delete
                chardelete = getans(i - 1, j, word1, word2,dp) + 1;
            }
            return dp[i][j]= min({insert,replace,chardelete});
        }

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>>dp(n1,vector<int> (n2,-1));
        int ans = getans(n1-1, n2-1, word1, word2,dp);
        return ans;
    }
};