class Solution
{
    public:
        bool isVowel(char ch)
        {
            string str = "aeiou";
            return (str.find(ch) != string::npos);
        }
    int maxVowels(string s, int k)
    {
        int n = s.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (isVowel(s[i]))
            {
                count++;
            }
            if (i >= k)
            {
                if (isVowel(s[i - k]))
                {
                    count--;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};