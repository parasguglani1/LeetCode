class Solution
{
    public:
        struct DSU
        {
            vector<int> sz;	// by size
            vector<int> parent;
            DSU(int n)
            {
                sz.resize(n, 0);
                parent.resize(n, 0);
                for (int i = 0; i < n; i++) parent[i] = i;
                for (int i = 0; i < n; i++) sz[i] = 1;
            }
            int find(int u)
            {
                if (parent[u] == u) return u;
                return parent[u] = find(parent[u]);
            }
            bool merge(int u, int v)
            {
                u = find(u);
                v = find(v);
                if (u == v) return false;
                if (sz[u] > sz[v])
                {
                    parent[v] = u;
                    sz[u] += sz[v];
                }
                else
                {
                    parent[u] = v;
                    sz[v] += sz[u];
                }
                return true;
            }
            int size(int x)
            {
                return sz[x];
            }
        };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector < int>> &g, vector< vector< int>> &q)
    {
        for (int i = 0; i < q.size(); i++)
        {
            q[i].push_back(i);
        }
        sort(g.begin(), g.end(), [](vector<int> &v1, vector<int> &v2)
        {
            return v1[2] < v2[2];
	});
        sort(q.begin(), q.end(), [](vector<int> &v1, vector<int> &v2)
        {
            return v1[2] < v2[2];
	});
        DSU d(n);

        int i = 0, j = 0;
        vector<bool> ans((int) q.size());
        while (j < (int) q.size())
        {
            while (i < (int) g.size() && g[i][2] < q[j][2])
            {
                d.merge(g[i][0], g[i][1]);
                i++;
            }
            if (d.find(q[j][0]) == d.find(q[j][1]))
            {
                ans[q[j].back()] = true;
            }
            j++;
        }
        return ans;
    }
};