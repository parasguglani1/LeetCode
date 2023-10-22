class Solution
{
    public:
        int maximumScore(vector<int> &nums, int k)
        {
            int ans = 0;
            int n = nums.size();
            int i = k-1, j = k+1;
            int mn = nums[k];
            ans=mn;
           	// ans=mn;
            while (i >= 0 || j < n)
            {
                if (i < 0 || (j < n && nums[j] > nums[i]))
                {
                    mn = min(mn, nums[j]);
                    ++j;
                }
                else
                {
                    mn = min(mn, nums[i]);
                    --i;
                }
                ans = max(ans, mn *(j - i - 1));
            }
            return ans;
        }
};