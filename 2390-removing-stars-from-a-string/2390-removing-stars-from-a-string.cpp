class Solution
{
    public:
        string removeStars(string s)
        {
            int n = s.length();
            string ans = "";
            int count = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '*')
                {
                    count++;
                }
                else
                {
                    if (count > 0)
                    {
                        s[i]='*';
                        count--;

                    }
                    else
                    {
                        // ans += s[i];
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                if(s[i]!='*')
                    ans+=s[i];
            }
            // reverse(ans.begin(), ans.end());
            return ans;
        }
};