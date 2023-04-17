class Solution
{
    public:
        vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
        {
            int n = candies.size();
            vector<bool> ans;
            int mx = *max_element(candies.begin(), candies.end());

            for (int i = 0; i < n; i++)
            {
                ans.push_back(candies[i] + extraCandies >= mx);
            }
            return ans;
        }
};