class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int n = s.size();
            if (n < 2)
            {
                return n;
            }
            int l = 0, r = 1;

            vector<int> freq(256);
            freq[s[l]]++;
            int ans = 1;
            while (r < n)
            {
                freq[s[r] ]++;
                while (freq[s[r]] > 1)
                {
                    freq[s[l] ]--;
                    l++;
                }
                r++;
                ans = max(ans, r - l);
            }
            return ans;
        }
};