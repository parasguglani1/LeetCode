class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &nums1, vector<int> &nums2)
        {
            vector<int> ans1,ans2;
            set<int> s1(nums1.begin(), nums1.end());
            set<int> s2(nums2.begin(), nums2.end());

            for (auto x: s1)
            {
                if (s2.count(x) == 0) ans1.push_back(x);
            }
            for (auto x: s2)
            {
                if (s1.count(x) == 0) ans2.push_back(x);
            }
            return {ans1,ans2};

        }
};