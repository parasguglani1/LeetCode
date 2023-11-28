class Solution
{
    public:
        int numberOfWays(string corridor)
        {
            vector<int> cnt;
            int mod = 1e9 + 7;
            int n = corridor.size();

            int Scnt = 0;
            int ways = 1;
            for (int i = 0; i < n; i++)
            {
                if (corridor[i] == 'S')
                {
                    Scnt++;
                    if (Scnt == 3)
                    {
                        Scnt = 1;
                        cnt.push_back(ways);
                        ways = 1;
                    }
                }
                else
                {
                    if (Scnt == 2)
                    {
                        ways++;
                    }
                }
            }
            if (cnt.empty() && Scnt < 2)
            {
                return 0;
            }
            if(Scnt==1)
            
            {
                return 0;
            }
            long long ans = 1;
            int sz = cnt.size();

            for (int i = 0; i < sz; i++)
            {
                ans *= cnt[i];
                ans %= mod;
            }

            return ans;
        }
};