class Solution
{
    public:
        int countPalindromicSubsequence(string s)
        {
            vector<int> first(26, -1), last(26, -1);
           	// int first[26] = {[0.. .25] = INT_MAX
           	// }, last[26] = {}, ans = 0;
            int ans=0;
            for (int i = 0; i < s.size(); ++i)
            {
                if (first[s[i] - 'a'] == -1)
                    first[s[i] - 'a'] = i;
                last[s[i] - 'a'] = i;
            }
            for (int i = 0; i < 26; ++i)
                if (first[i] < last[i])
                    ans += unordered_set<char> (begin(s) + first[i] + 1, begin(s) + last[i]).size();
            return ans;

           	// having atleast1 *having atleast 2 *having atleast 1

        }
};