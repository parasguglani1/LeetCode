class Solution
{
    public:
        char findTheDifference(string s, string t)
        {
            int n = s.size();
            for (int i = 0; i < n; i++)
                t[i + 1] += t[i] - s[i];
            return t[n];
        }
};