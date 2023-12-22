class Solution
{
    public:
        int maxScore(string s)
        {
            int n = s.size();
            int cnt1 = count(s.begin(), s.end(), '1');
            int ans = 0, cnt0 = 0;
            
            // if(s[0]=='0')
            // {
            //     cnt0++;
            // }
            // else
            // {
            //     cnt1--;
            // }
            for (int i = 0; i < n-1; i++)
            {
                if (s[i] == '0')
                {
                    cnt0++;
                }
                else
                {
                    cnt1--;
                }
                ans = max(ans, cnt0 + cnt1);

            }
            return ans;
        }
};