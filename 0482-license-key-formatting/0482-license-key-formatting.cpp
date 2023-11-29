class Solution
{
    public:
        string licenseKeyFormatting(string s, int k)
        {
            reverse(s.begin(), s.end());
            int i = 0, n = s.size();
            string ans = "";
            int cnt = 0;
            while (i < n)
            {
                if(s[i]=='-')
                {
                    i++;
                    continue;
                }
                if (cnt == k)
                {
                    ans += '-';
                    cnt=0;
                }
                if(s[i]>='a')
                {
                    s[i]-=32;
                }
                
                ans += s[i++];
                cnt++;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};