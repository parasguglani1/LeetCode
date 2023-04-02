class Solution
{
    public:
        vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
        {
            sort(potions.begin(), potions.end());
            int n = spells.size();
            int m = potions.size();
            vector<int> ans(n);
            for (int i = 0; i < n; i++)
            {
                long long fnd = ceil((success *1.0) / spells[i]);
                int ind = lower_bound(potions.begin(), potions.end(), fnd) - potions.begin() ;
                int p = m - ind;
                ans[i] = p;
            }
            return ans;
        }
};