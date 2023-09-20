class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int n = nums.size();
            // vector<int> pref(n + 1), suff(n + 1);
            int sum = nums[0];
            map<int, int> pmp, smp;
            pmp.insert({ nums[0],1 });
            

            for (int i = 1; i < n; i++)
            {
                sum+= nums[i];
                pmp.insert({ sum,
                    i + 1 });
            }
            smp.insert({ nums[n-1],1 });
            int sum2=nums[n-1];

            for (int i = n - 2; i >= 0; i--)
            {
                sum2+=nums[i];
                smp.insert({ sum2,
                    n - i });
            }
            int ans = INT_MAX;
            for (auto c: pmp)
            {
                if (c.first == x)
                {
                    ans = min(ans, c.second);
                }
            }
            for (auto c: smp)
            {
                if (c.first == x)
                {
                    ans = min(ans, c.second);
                }
            }

            for (auto c: pmp)
            {
                int fnd = x - c.first;
               	//             modify this line
                if (smp[fnd] && c.second + smp[fnd] < n)
                {
                    ans = min(ans, smp[fnd] + c.second);
                }
            }
           	// cout<<ans<<endl;
            if (ans == INT_MAX)
            {
                return -1;
            }
            return ans;
        }
};