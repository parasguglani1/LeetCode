/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
    public:
        Node* dfs(Node *adj, Node *node, unordered_map<Node*, Node*> &vis)
        {

            adj = new Node(node->val);
            vis[node] = adj;
            Node * m;
            for (auto p: node->neighbors)
            {
                if (!vis[p])
                    m = dfs(adj, p, vis);
                else
                    m = vis[p];
                adj->neighbors.push_back(m);
            }
            return adj;
        }
    Node* cloneGraph(Node *node)
    {
        if (!node)
            return 0;
        Node * adj;
        unordered_map<Node*, Node*> vis;
        adj = dfs(adj, node, vis);
        return adj;
    }
};