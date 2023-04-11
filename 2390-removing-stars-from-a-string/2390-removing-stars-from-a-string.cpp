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
                        count--;
                    }
                    else
                    {
                        ans += s[i];
                    }
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};