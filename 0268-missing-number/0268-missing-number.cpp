class Solution
{
    public:
        int missingNumber(vector<int> &nums)
        {
            int sum = 0;
            int mx = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                sum += nums[i];
                mx = max(mx, nums[i]);
            }
            int reqsum = (n *(n + 1)) / 2;
            return reqsum - sum;
        }
};