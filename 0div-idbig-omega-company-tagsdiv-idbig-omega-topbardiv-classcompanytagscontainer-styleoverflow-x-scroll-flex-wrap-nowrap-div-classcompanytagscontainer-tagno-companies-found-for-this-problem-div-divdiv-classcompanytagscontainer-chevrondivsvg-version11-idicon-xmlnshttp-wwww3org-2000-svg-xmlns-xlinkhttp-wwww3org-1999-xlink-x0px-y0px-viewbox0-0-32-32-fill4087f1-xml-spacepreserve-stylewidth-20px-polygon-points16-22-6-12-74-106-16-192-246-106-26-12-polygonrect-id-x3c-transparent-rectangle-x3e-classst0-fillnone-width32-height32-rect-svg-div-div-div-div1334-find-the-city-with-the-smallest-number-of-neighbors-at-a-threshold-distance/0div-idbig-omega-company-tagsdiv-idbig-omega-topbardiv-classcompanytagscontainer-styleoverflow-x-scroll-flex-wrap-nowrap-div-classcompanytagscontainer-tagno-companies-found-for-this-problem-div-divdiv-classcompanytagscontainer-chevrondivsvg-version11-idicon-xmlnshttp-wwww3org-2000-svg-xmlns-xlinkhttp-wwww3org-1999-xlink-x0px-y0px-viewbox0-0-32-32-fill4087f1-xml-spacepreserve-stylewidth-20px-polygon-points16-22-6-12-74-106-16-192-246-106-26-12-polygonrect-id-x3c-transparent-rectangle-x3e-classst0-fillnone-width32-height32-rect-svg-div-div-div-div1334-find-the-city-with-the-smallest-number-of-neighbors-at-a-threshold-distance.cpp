class Solution
{
    public:
        int findTheCity(int n, vector<vector < int>> &edges, int dis)
        {
            //use dijikstra
            int m = edges.size();
            int mx = n - 1;
            int ans = n - 1;
            vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>> ());
            
            for (auto x: edges)
            {
                graph[x[0]].push_back({ x[1],
                    x[2] });
                graph[x[1]].push_back({ x[0],
                    x[2] });
            }

            for (int i = n - 1; i >= 0; i--)
            {
                priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
                vector<int> vis(n, 0);
                int reachable = 0;
                vis[i]=1;
                vector<int> distance(n,INT_MAX);
                distance[i]=0;
                for (auto x: graph[i])
                {
                    if (x.second <= dis)
                    {
                        {
                            pq.push({ x.second,
                                x.first });
                            // reachable++;
                            distance[x.first]=x.second;
                            vis[x.first]=1;
                        }
                    }
                }
                while (!pq.empty())
                {
                    auto x = pq.top();
                    pq.pop();

                    int ind = x.second;
                    int curdis = x.first;
                    for (auto y: graph[ind])
                    {
                        int totaldis=curdis + y.second;
                        if ( totaldis <= dis && totaldis<distance[y.first])
                        {
                            pq.push({ totaldis,
                                y.first });
                            // reachable++;
                            // vis[y.first]=1;
                            distance[y.first]=totaldis;
                        }
                    }
                }
                
                for(int i=0;i<n;i++)
                {
                    if(distance[i]<=dis)
                    {
                        reachable++;
                    }
                }

                // cout << reachable << " " << mx<<" "<<i << endl;
                

                if (reachable-1 < mx)
                {
                    
                    // cout << reachable << " " << mx<<" "<<i << endl;
                    mx = reachable-1;
                    ans = i;
                }
            }
            return ans;
        }
};