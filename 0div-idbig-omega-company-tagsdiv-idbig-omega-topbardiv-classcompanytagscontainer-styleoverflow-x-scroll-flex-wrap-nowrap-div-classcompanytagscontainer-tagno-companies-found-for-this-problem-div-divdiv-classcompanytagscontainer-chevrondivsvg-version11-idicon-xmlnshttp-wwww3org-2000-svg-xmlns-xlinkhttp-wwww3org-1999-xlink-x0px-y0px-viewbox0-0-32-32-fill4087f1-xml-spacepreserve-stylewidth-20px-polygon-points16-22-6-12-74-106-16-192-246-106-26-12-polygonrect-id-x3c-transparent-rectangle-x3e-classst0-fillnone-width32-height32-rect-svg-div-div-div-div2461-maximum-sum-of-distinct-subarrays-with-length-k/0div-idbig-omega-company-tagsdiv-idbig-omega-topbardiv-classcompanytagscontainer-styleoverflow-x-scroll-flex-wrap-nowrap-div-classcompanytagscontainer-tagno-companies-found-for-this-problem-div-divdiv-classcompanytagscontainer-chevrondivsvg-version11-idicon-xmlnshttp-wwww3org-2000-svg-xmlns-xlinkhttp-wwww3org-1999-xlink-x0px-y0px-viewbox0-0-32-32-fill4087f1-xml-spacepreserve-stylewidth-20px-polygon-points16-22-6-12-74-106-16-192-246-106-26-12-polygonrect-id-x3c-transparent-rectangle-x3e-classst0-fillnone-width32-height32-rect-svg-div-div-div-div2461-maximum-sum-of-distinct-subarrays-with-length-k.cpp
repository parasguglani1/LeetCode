class Solution
{
    public:
        long long maximumSubarraySum(vector<int> &nums, int k)
        {
            long long ans = 0, sum = 0;
            int i = 0, j = 0;
            set<int> st;
            while (i < nums.size())
            {
                if (i - j < k && st.size() < k)
                {
                    while (st.size() > 0 && st.count(nums[i]) > 0)
                    {
                        sum -= nums[j];
                        st.erase(nums[j++]);
                    }
                    sum += nums[i];
                    st.insert(nums[i++]);
                }
                else
                {
                    if (i - j == k && st.size() == k)
                    {
                        ans = max(ans, sum);
                    }
                    sum -= nums[j];
                    st.erase(nums[j++]);
                }
            }
            if (i - j == k && st.size() == k)
                ans = max(ans, sum);
            return ans;
        }
};