class Solution
{
    public:
        int dfs(vector<int> adj[], int n, int u, int prev, int seats, long long &ans)
        {
           	//count no. of peoples
            int num = 1;
            for (auto v: adj[u])
            {
                if (v == prev)
                {
                    continue;
                }
                else
                {
                    num = num + dfs(adj, n, v, u, seats, ans);
                }
            }
            if (u > 0)
            {
                ans += (num + seats - 1) / seats;
            }
            return num;
        }
    long long minimumFuelCost(vector<vector < int>> &roads, int seats)
    {
        long long ans = 0;
        int n = roads.size();
        vector<int> adj[n + 1];
        for (auto it: roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(adj, n, 0, -1, seats, ans);
        return ans;
    }
};