class Solution
{
    public:
        vector<int> avoidFlood(vector<int> &rains)
        {
            int n = rains.size();
            unordered_map<int, int> full;
            set<int> zeros;
            vector<int> ans(n, -1);
            for (int i = 0; i < n; i++)
            {
                if (rains[i] == 0)
                {
                    zeros.insert(i);
                }
                else
                {
                    if (full.count(rains[i]))
                    {
                        auto it = zeros.lower_bound(full[rains[i]]);
                        if (it == zeros.end()) return {};
                        ans[*it] = rains[i];
                        zeros.erase(it);
                        full[rains[i]] = i;
                    }
                    else
                    {
                        full[rains[i]] = i;
                    }
                }
            }
            for (auto &zero: zeros)
            {
                ans[zero] = 1;
            }
            return ans;
        }
};