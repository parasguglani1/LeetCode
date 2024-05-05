class Solution
{
    public:
        int minAnagramLength(string s)
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < s.size(); i++)
            {
                mp[s[i]]++;
            }
            int cd = mp[s[0]];
            for (auto x: mp)
            {
                cd = __gcd(cd, x.second);
            }
            int sum = 0;
            for (auto x: mp)
            {
                sum += x.second;
            }
            return sum / cd;
        }
};