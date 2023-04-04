class Solution
{
    public:
        vector<int> freq;

    void clearvec()
    {
        for (int i = 0; i < 26; i++)
        {
            freq[i] = 0;
        }
    }
    int partitionString(string s)
    {
        freq.resize(26);
        // clearvec();
        
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (freq[s[i]-'a'])
            {
                ans++;
                clearvec();
            }
            freq[s[i]-'a']++;
        }
        return ans+1;
    }
};