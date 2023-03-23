class Solution
{
    void dfs(vector<vector < int>> &edges, int src, vector< int > &vis)
    {
        if (vis[src]) return;

        vis[src] = 1;

        for (auto &nbr: edges[src])
        {
            dfs(edges, nbr, vis);
        }
    }
    public:
        int makeConnected(int n, vector<vector < int>> &connections)
        {

            int m = connections.size();

            if (n - 1 > m) return -1;

            vector<vector < int>> edges(n);
            vector<int> vis(n);
            int compo = 0;

            for (auto &con: connections)
            {
                int u = con[0], v = con[1];

                edges[u].push_back(v);
                edges[v].push_back(u);
            }

            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    dfs(edges, i, vis);
                    compo++;
                }
            }

            return compo - 1;
        }
};