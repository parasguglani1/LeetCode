class Solution
{
    public:
        static bool cmp(string str1, string str2)
        {
            return str1.size() < str2.size();
        }
    bool check(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        if (n != m + 1)
        {
            return false;
        }
        int i = 0, j = 0;
        
        while(i<n)
        {
            if(j<m&&str1[i]==str2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==n &&j==m)
        {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string> &words)
    {
       	//sort based on size

        int n = words.size();
        int mx = 1;
        sort(words.begin(), words.end(), cmp);
       	//dp
       	// for(auto x:words)
       	// {
       	//     cout<<x<<' ';
       	// }
       	// cout<<endl;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[i], words[j]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(dp[i], mx);
                }
            }
        }
        return mx;
    }
};