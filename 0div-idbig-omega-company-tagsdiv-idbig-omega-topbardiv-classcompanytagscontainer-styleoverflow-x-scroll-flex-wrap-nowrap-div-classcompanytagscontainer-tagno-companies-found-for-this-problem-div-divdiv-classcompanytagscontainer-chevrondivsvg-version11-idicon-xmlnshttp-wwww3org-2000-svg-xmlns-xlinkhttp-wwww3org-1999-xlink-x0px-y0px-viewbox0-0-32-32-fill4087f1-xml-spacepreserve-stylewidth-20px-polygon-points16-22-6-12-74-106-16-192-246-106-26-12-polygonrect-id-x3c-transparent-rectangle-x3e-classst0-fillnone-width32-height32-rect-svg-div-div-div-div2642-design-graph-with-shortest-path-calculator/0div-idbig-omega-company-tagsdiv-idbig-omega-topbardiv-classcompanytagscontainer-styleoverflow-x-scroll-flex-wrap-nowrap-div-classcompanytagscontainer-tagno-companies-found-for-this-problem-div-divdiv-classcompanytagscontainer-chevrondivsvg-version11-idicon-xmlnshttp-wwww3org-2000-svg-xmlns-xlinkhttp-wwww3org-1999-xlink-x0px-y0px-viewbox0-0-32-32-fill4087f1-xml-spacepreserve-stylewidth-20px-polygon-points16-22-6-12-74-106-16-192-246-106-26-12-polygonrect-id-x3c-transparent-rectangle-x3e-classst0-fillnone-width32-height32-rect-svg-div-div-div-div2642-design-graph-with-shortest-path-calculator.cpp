
#define pb push_back
#define ff first
#define ss second
class Graph
{
public:
    vector<pair<int, int>> adjacency[105];
    int size;
    Graph(int n, vector<vector<int>> &edg)
    {
        for (auto x : edg)
        {
            adjacency[x[0]].pb({x[1], x[2]});
        }
        size = n;
    }

    void addEdge(vector<int> edg)
    {
        adjacency[edg[0]].pb({edg[1], edg[2]});
    }

    int shortestPath(int node1, int node2)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> distt(size + 1, 1e9 + 1);
        pair<int, int> curr={0,node1};

        q.push(curr);
        distt[node1] = 0;
        while (!q.empty())
        {
            pair<int, int> curr = q.top();
            q.pop();
            int node = curr.ss;
            int dist = curr.ff;
            for (auto x : adjacency[node])
            {
                int relax = dist + x.ss;
                if (relax < distt[x.ff])
                {
                    distt[x.ff] = relax;
                    q.push({relax, x.ff});
                }
            }
        }
        if (distt[node2] != 1e9 + 1)
        {
            return distt[node2];
        }
       else return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */