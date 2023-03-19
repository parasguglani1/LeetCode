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
                if (tempsum < 0)
                {
                    tempsum = 0;
                }

                tempsum += nums[i];
            }
            maxsum = max(tempsum, maxsum);

            return maxsum;
        }
};