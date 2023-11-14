class Solution
{
    public:
       	//space optimisation
        int numDistinct(string s, string t)
        {

            int n = s.size();
            int m = t.size();
            vector<long long>curr(m+1,0),prev(m+1,0);
            prev[0]=curr[0]=1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    int nottaken = prev[j];
                    int taken = 0;

                    if (s[i - 1] == t[j - 1])
                    {
                        taken = prev[j - 1];
                    }

                    curr[j] = (long) taken + nottaken;
                }
                prev=curr;
            }

            int ans = prev[m];
            return ans;
        }
};