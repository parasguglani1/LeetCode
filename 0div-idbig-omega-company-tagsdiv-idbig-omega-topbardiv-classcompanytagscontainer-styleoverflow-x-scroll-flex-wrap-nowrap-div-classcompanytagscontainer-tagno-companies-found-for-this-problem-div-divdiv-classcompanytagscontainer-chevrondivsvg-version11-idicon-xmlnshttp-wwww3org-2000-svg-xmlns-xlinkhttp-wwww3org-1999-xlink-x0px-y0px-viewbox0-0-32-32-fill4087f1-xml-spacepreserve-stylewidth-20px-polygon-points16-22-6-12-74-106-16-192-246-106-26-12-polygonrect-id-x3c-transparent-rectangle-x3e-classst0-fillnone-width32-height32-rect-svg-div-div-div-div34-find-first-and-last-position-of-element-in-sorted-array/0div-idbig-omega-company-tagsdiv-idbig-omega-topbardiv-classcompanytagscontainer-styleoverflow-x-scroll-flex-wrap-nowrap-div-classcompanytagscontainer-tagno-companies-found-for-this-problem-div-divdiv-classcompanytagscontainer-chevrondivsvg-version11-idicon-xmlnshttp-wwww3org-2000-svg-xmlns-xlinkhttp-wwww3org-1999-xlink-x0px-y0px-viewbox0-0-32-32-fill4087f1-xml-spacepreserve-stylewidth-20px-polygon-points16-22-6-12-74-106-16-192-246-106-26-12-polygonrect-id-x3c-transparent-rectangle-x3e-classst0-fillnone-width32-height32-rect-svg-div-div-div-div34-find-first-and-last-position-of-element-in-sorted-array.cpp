class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            auto a1 = lower_bound(nums.begin(), nums.end(), target);
            auto a2 = upper_bound(nums.begin(), nums.end(), target);
            if (a1 == nums.end() ||*a1!=target)
            {
                return { -1,
                    -1 };
            }
            int ans1 = a1 - nums.begin();
            int ans2=a2-nums.begin();
            return {
                ans1,
                ans2 - 1
            };
        }
};