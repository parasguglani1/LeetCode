class Solution
{
    public:
        vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
        {
            int n = words.size();

            vector<int> freq;
            for (auto x: words)
            {
                vector<int> a(26,0);
                for (auto c: x)
                {
                    a[c - 'a']++;
                }
                int smallest = 0;
                for (auto i: a)
                {
                    if (i)
                    {
                        smallest = i;
                        break;
                    }
                }
                freq.push_back(smallest);
            }
            sort(freq.begin(),freq.end());
            vector<int> ans;

            for (auto x: queries)
            {
                vector<int> a(26,0);
                for (auto c: x)
                {
                    a[c - 'a']++;
                }
                int smallest = 0;
                for (auto i: a)
                {
                    if (i)
                    {
                        smallest = i;
                        break;
                    }
                }
                
                ans.push_back(freq.end()-upper_bound(freq.begin(),freq.end(),smallest));
            }
            return ans;
        }
};