class Solution
{
    public:
       	//space optimize
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1,0),curr(m+1,0);

        for (int j = 0; j <= m; j++)
        {
        prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            curr[0]=i;
            for (int j = 1; j <= m; j++)
            {
                int same = 0, insert = 1e9, replace = 0, chardelete = 1e9;
                same = prev[j - 1];
                replace = same;
                if (word1[i-1] != word2[j-1])
                {
                   	//insert
                    insert = curr[j-1] + 1;;

                    replace++;
                   	//delete
                    chardelete = prev[j] + 1;
                }
                curr[j] = min({ insert,
                    replace,
                    chardelete });
            }
            prev=curr;
        }

        int ans = prev[m];
       	// int ans = getans(n1-1, n2-1, word1, word2,dp);
        return ans;
    }
};