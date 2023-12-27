class Solution
{
#define ll long long
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        ll res = 0, sum = 0;
        ll i = 0, j = 0, n = 0;
        set<int> st;
        while (i < nums.size())
        {
            if (i - j < k && st.size() < k)
            {
                while (st.size() > 0 && (st.find(nums[i]) != st.end()))
                {
                    sum -= nums[j];
                    st.erase(nums[j]);
                    j++;
                }
                sum += nums[i];
                st.insert(nums[i]);
                i++;
            }
            else
            {
                if (i - j == k && st.size() == k)
                {
                    res = max(res, sum);
                }
                sum -= nums[j];
                st.erase(nums[j]);
                j++;
            }
        }
        if (i - j == k && st.size() == k)
            res = max(res, sum);
        return res;
    }
};
