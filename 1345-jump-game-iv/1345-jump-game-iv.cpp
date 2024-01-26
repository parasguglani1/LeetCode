class Solution
{
    public:
        int minJumps(vector<int> &arr)
        {
            unordered_map<int, vector < int>> m;
            int n = size(arr);
            for (int i = 0; i < n; ++i)
                m[arr[i]].push_back(i);
            queue<int> q;
            q.push(0);
            vector<bool> visited(n);
            visited[0] = true;
            int ans = 0;
            while (!q.empty())
            {
                int sz = size(q);
                while (sz--)
                {
                    int i = q.front();
                    q.pop();
                    if (i == n - 1)
                        return ans;
                    if (i + 1 < n && !visited[i + 1])
                    {
                        q.push(i + 1);
                        visited[i + 1] = true;
                    }
                    if (i - 1 >= 0 && !visited[i - 1])
                    {
                        q.push(i - 1);
                        visited[i - 1] = true;
                    }
                    for (int j: m[arr[i]])
                    {
                        if (!visited[j])
                        {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                    m[arr[i]].clear();
                }
                ++ans;
            }
            return -1;
        }
};