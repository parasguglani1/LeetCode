class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int a, b;
            auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
            auto it2 = std::lower_bound(nums.begin(), nums.end(), target + 1);
            if (it1 != nums.end() && *it1 == target)
            {
                a = it1 - nums.begin();
                b = it2 - nums.begin() - 1;
                return {
                    a,
                    b
                };
            }
            return { -1,
                -1 };
        }
};