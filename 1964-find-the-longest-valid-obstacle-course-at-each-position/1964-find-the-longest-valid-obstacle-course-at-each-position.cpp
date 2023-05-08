class Solution
{
    public:
        vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
        {
            vector<int> ans, v;
            int n = obstacles.size();
            for (auto &i: obstacles)
            {
                if (v.empty() || v.back() <= i)
                {
                    v.push_back(i);
                    ans.push_back(v.size());
                }
                else
                {
                    int x = upper_bound(v.begin(), v.end(), i) - v.begin();
                    ans.push_back(x + 1);
                    v[x] = i;
                }
            }
            return ans;

        }
};