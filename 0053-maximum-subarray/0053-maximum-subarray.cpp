class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            int n = nums.size();
            int tempsum = nums[0];
            int maxsum = tempsum;
            for (int i = 1; i < n; i++)
            {
                maxsum = max(tempsum, maxsum);
                tempsum=max(nums[i],tempsum+nums[i]);
            }
            maxsum = max(tempsum, maxsum);

            return maxsum;
        }
};