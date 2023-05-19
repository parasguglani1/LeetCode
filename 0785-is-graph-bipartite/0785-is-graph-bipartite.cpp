class Solution
{
    public:
        bool isBipartite(vector<vector < int>> &v)
        {
            int n = v.size();
            vector<int> color(n, -1);
            color[0] = 0;
            for (int i = 0; i < n; i++)
            {
                for (auto x: v[i])
                {
                    if (color[x] == -1)
                    {
                        color[x] = 1 - color[i];
                    }
                    else if (color[x] == color[i])
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }};