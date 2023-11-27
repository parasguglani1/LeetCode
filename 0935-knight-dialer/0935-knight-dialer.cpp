class Solution
{
    public:
        int knightDialer(int n)
        {
           	// 0-4,6
           	// 2-7,9
           	// 3-8,4
           	// 4- 3,9,0
           	// 5-            	// 1-8,6

           	// 6- 1,7,0
           	// 7-2,6
           	// 8- 1,3
           	// 9-2,4
            int mod = 1e9 + 7;

            vector < long long > cnt(10, 1), ncnt(10, 1);

            for (int i = 0; i < n - 1; i++)
            {
                ncnt[0] = cnt[4] + cnt[6];
                ncnt[1] = cnt[6] + cnt[8];
                ncnt[2] = cnt[7] + cnt[9];
                ncnt[3] = cnt[4] + cnt[8];
                ncnt[4] = cnt[3] + cnt[9] + cnt[0];
                ncnt[5] = 0;
                ncnt[6] = cnt[7] + cnt[1] + cnt[0];
                ncnt[7] = cnt[2] + cnt[6];
                ncnt[8] = cnt[1] + cnt[3];
                ncnt[9] = cnt[2] + cnt[4];
                for (int j = 0; j < 10; j++)
                {
                    ncnt[j] %= mod;
                   	// cout << ncnt[j] << ' ';
                }
                // cout << endl;
                cnt = ncnt;
            }
            long long ans=0;
            for (int j = 0; j < 10; j++)
            {
                ans +=ncnt[j];
                ans %= mod;
            }

            return ans;
        }
};