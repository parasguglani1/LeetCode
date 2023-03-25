class Solution {
private:
	void dfs(int node,vector<vector<int>> &graph,vector<bool> &vis,int &cnt){
		vis[node] = true;
		cnt++;
		for(auto it : graph[node]){
			if(!vis[it]){
				dfs(it,graph,vis,cnt);
			}
		}
	}
public:
	long long countPairs(int n, vector<vector<int>>& edges) {

		vector<vector<int>> graph(n);

		for(int i = 0; i < edges.size(); i++){
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);   
		}

		vector<bool> vis(n,false);

		vector<long long> v;

		for(int i = 0; i < n; i++){
			if(!vis[i]){
				int cnt = 0;
				dfs(i,graph,vis,cnt);
				v.push_back(cnt);
			}
		}

		if(v.size() == 1) return 0;

		long long ans = 0,sum = 0;

		int sz = v.size();

		for(int i = 0; i < sz; i++){
			ans += (sum*v[i]);
			sum += v[i];
		}

		return ans;
	}
};
