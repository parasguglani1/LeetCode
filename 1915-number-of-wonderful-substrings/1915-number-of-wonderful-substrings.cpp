class Solution
{
    #define ll long long
    public:
        long long wonderfulSubstrings(string word)
        {
            unordered_map<ll, ll> mp;
            ll ans = 0, mask = 0;
            mp[0] = 1;
            for (int i = 0; i < word.size(); i++)
            {
               	//prefix sum xor
                mask = mask ^ (1 << (word[i] - 'a'));
                ans += mp[mask];
               	// bits toggling
                for (int j = 0; j < 12; j++)
                {
                    ans += mp[mask ^ (1 << j)];
                }
                mp[mask]++;
            }

            return ans;
        }
};