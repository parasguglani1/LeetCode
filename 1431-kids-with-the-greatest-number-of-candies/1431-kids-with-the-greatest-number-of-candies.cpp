class Solution
{
    public:
        vector<bool> kidsWithCandies(vector<int> &c, int e)
        {
            vector<bool> ans;
            int mx = *max_element(c.begin(), c.end())-e;
            for (auto &x: c)
            {
                ans.push_back(x >= mx);
            }
            return ans;
        }
};