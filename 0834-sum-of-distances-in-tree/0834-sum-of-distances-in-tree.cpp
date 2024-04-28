class Solution
{
    private:
       	// Function for the first DFS traversal
        int dfs1(int node, int parent, vector<int> adj[], vector<int> &count_child, vector<int> &ans)
        {
            int sum = 0;
            int val = 0;
           	// Traverse through the adjacent nodes of the current node
            for (auto it: adj[node])
            {
                if (it != parent)
                {
                	// Ensure not going back to parent
                   	// Recursively call dfs1 for child nodes
                    sum += dfs1(it, node, adj, count_child, ans);
                    val += ans[it];	// Sum up the values from the child nodes
                }
            }
            ans[node] = sum + val;	// Calculate the sum of distances for the current node
            return count_child[node] = sum + 1;	// Update the count_child array with the count of nodes in the subtree
        }

   	// Function for the second DFS traversal
    void dfs2(int node, int parent, vector<int> adj[], vector<int> &count_child, vector<int> &ans, int n)
    {
       	// Traverse through the adjacent nodes of the current node
        for (auto it: adj[node])
        {
            if (it != parent)
            {
            	// Ensure not going back to parent
               	// Update the sum of distances for child nodes based on parent node
                ans[it] += ans[node] - (ans[it] + count_child[it]) + (n - count_child[it]);
               	// Recursively call dfs2 for child nodes
                dfs2(it, node, adj, count_child, ans, n);
            }
        }
    }

    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector < int>> &edges)
        {
            vector<int> adj[n];
           	// Building adjacency list
            for (auto it: edges)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            vector<int> ans(n, 0);	// To store the sum of distances for each node
            vector<int> count_child(n, 0);	// To store the count of nodes in the subtree rooted at each node
            dfs1(0, -1, adj, count_child, ans);	// Perform the first DFS traversal
            dfs2(0, -1, adj, count_child, ans, n);	// Perform the second DFS traversal
            return ans;	// Return the resulting array containing the sum of distances for each node
        }
};