class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int n = nums.size();
            int max_ending_here = nums[0], min_ending_here = nums[0], ans = nums[0];

            for (int i = 1; i < n; i++)
            {
                int temp = max({ nums[i],
                    max_ending_here *nums[i],
                    min_ending_here *nums[i] });
                 min_ending_here = min({ nums[i],
                    max_ending_here *nums[i],
                    min_ending_here *nums[i] });
                max_ending_here=temp;
                
                ans=max(ans,max_ending_here);
            }
            return ans;
        }
};