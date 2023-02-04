class Solution
{
    public:
        bool isVowel(char c)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
                return true;
            return false;
        }
    string reverseVowels(string s)
    {
        vector<char> v;
        for (auto x: s)
        {
            if (isVowel(x))
            {
                v.push_back(x);
            }
        }
        reverse(v.begin(), v.end());
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (isVowel(s[i]))
            {
                s[i] = v[j++];
            }
        }
        return s;
    }
};