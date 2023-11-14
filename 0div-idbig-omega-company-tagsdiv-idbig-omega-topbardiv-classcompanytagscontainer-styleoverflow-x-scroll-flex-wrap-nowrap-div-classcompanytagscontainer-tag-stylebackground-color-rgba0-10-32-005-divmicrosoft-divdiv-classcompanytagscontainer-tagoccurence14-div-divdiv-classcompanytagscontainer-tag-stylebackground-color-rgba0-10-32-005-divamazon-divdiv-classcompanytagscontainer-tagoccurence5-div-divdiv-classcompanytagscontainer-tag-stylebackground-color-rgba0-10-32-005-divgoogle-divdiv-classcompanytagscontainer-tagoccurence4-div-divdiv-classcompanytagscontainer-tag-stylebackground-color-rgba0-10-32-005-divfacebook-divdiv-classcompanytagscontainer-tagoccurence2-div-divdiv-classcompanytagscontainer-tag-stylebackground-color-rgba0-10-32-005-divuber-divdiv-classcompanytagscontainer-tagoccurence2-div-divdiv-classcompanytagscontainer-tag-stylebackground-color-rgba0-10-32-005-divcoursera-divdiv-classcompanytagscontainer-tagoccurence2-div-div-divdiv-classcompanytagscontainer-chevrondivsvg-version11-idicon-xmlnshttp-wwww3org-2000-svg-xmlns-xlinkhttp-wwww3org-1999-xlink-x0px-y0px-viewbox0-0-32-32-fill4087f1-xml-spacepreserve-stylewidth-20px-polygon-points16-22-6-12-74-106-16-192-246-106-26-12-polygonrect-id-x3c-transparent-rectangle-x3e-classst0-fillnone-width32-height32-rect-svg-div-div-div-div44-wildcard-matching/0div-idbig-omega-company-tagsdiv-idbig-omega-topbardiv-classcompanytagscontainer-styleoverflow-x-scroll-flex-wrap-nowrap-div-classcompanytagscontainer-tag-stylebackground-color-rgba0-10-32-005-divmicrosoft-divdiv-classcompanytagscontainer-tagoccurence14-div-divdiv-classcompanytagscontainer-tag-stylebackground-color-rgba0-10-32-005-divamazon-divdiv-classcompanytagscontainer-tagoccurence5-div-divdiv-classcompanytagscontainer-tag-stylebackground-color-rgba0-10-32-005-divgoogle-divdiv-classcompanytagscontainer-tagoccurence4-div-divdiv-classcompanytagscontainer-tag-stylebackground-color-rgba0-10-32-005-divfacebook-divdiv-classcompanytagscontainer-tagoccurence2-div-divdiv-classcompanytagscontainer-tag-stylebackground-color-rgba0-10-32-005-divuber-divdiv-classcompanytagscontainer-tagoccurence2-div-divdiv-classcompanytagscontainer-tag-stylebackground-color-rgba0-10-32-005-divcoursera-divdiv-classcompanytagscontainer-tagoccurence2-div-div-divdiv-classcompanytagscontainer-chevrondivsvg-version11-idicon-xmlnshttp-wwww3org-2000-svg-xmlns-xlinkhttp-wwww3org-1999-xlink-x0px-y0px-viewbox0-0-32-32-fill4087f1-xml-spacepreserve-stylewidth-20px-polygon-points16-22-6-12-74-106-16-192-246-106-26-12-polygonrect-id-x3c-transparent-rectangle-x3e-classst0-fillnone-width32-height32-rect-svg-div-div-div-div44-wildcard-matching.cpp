class Solution
{
    public:
       	//space optimize
        bool isMatch(string s, string p)
        {
            int n = s.size();
            int m = p.size();
           	// vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
            vector<int> prev(m + 1, 0), curr(m + 1, 0);
            prev[0] = 1;

            bool flag = true;

            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] != '*')
                {
                    flag = false;
                   	// break;
                }
                prev[j] = curr[j] = flag;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    {
                        curr[j] = prev[j - 1];
                    }
                    else if (p[j - 1] == '*')
                    {
                        bool possible = false;
                        possible |= prev[j];
                        possible |= curr[j - 1];
                        curr[j] = possible;
                    }
                    else curr[j] = false;
                }

                prev = curr;
            }

            return prev[m];
        }
};