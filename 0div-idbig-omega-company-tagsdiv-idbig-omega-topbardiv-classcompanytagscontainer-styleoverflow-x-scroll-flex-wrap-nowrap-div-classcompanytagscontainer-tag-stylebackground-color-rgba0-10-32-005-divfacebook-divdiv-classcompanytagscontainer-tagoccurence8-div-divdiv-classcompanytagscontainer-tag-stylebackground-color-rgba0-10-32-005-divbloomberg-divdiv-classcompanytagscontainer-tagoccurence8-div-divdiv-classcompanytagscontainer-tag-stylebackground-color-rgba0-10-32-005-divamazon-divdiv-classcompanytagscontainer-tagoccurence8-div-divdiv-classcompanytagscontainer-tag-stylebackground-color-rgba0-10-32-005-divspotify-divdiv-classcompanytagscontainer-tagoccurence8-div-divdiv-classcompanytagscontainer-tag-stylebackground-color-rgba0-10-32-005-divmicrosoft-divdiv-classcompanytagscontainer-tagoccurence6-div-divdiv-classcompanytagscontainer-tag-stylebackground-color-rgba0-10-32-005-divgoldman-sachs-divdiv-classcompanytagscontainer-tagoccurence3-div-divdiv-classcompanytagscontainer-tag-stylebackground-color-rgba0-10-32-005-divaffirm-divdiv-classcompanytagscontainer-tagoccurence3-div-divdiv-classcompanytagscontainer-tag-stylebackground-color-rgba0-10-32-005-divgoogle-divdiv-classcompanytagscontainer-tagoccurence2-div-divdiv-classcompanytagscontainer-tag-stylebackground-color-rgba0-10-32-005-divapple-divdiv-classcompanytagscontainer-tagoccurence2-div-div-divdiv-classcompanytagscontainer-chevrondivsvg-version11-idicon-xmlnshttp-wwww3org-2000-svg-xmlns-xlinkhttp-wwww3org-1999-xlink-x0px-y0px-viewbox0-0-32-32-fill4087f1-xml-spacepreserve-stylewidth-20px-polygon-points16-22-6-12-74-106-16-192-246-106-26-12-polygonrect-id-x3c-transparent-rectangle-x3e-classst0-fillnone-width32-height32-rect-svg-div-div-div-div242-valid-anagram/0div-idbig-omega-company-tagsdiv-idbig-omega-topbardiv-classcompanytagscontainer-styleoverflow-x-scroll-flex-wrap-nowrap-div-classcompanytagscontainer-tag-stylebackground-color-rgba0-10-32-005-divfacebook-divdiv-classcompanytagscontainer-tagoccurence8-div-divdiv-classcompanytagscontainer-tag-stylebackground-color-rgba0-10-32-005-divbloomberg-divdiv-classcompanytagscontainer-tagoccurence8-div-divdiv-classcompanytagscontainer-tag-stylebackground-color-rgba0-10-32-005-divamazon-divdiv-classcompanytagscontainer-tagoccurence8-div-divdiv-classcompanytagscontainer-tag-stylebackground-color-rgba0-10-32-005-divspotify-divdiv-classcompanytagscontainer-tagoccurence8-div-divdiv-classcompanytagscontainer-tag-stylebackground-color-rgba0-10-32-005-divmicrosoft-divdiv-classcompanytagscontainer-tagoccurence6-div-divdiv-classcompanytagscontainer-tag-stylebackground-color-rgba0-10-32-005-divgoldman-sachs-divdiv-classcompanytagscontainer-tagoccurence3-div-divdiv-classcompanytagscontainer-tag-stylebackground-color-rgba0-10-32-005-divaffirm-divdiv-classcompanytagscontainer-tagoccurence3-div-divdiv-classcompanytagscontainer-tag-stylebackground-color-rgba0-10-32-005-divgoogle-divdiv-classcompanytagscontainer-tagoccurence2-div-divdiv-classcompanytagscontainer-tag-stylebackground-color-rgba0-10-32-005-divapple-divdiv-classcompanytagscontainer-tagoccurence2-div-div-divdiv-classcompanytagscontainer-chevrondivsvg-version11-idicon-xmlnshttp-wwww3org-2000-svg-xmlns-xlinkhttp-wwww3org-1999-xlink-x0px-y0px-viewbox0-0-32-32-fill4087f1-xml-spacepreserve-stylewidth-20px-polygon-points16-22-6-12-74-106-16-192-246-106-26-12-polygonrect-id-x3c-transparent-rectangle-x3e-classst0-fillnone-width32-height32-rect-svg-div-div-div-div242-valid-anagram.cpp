class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            vector<int> scnt(26, 0), tcnt(26, 0);

            for (auto x: s)
            {
                scnt[x - 'a']++;
            }
            for (auto x: t)
            {
                tcnt[x - 'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                if (scnt[i] != tcnt[i])
                {
                    return false;
                }
            }

            return true;
        }
};