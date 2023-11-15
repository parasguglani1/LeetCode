class Solution
{
    public:
        vector<int> largestDivisibleSubset(vector<int> &nums)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> dp(n, 1);
            int mx = 1;
            vector<int> prev(n, 0);
            
            for(int i=0;i<n;i++)
            {
                prev[i]=i;
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] % nums[j] == 0)
                    {
                        if (dp[j] + 1 > dp[i])
                        {
                            dp[i] = max(dp[i], dp[j] + 1);
                            prev[i]=j;
                        }
                        mx = max(dp[i], mx);
                    }
                }
            }
            vector<int> ans;
            for(int i=0;i<n;i++)
            {
                if(dp[i]==mx)
                {
                    // ans.push_back(nums[i]);
                    while(prev[i]!=i)
                    {
                        ans.push_back(nums[i]);
                        i=prev[i];
                    }
                    ans.push_back(nums[i]);

                    break;
                }
                
            }
            cout << mx << endl;
            return ans;
        }
};