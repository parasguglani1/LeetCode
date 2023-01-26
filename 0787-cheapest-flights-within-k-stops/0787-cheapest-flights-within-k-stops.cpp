class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            vector<int> dis(n, 1e9);
            dis[src] = 0;
            for (int i = 0; i <= k; i++)
            {
                vector<int> temp(dis);
                for (auto it: flights) temp[it[1]] = min(temp[it[1]], dis[it[0]] + it[2]);
                dis = temp;
            }
            return dis[dst] == 1e9 ? -1 : dis[dst];
        }
};