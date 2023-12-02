class Solution
{
    public:
        int countCharacters(vector<string> &words, string chars)
        {
            map<char, int> mp,temp;
            for (auto &x: chars)
            {
                mp[x]++;
            }
            int ans = 0;

            for (auto &x: words)
            {
                temp=mp;
                bool add = true;
                for (auto &y: x)
                {
                    if (temp[y] > 0)
                    {
                        temp[y]--;
                    }
                    else
                    {
                        add = false;
                        continue;
                    }
                }

                if (add)
                {
                    ans += x.size();
                   
                }
            }
            return ans;
        }
};