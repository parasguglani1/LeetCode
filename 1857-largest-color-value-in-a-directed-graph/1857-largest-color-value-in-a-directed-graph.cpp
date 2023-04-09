class Solution {
public:

   int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.size();

        vector<int> adj[n];

        //for indegree
        vector<int> indegree(n, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;

        //for count of parent node color values
        vector< vector<int> > cnt(n , vector<int> (26,0));

        for(int i =0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

  //total number of nodes traversed for cyclic graph detection
        int numberOfNodes = 0; 
        int ans = 0;

        while(!q.empty()){
           int size = q.size();

           for(int i =0; i<size; i++){
               int node = q.front();

               q.pop();

               numberOfNodes++;

               cnt[node][colors[node]-'a']++;

               ans = max(ans, cnt[node][colors[node]-'a']);

               //traversing the adjacency
               for(auto it : adj[node]){

                   for(int k =0; k<26; k++){
                       cnt[it][k] = max(cnt[it][k], cnt[node][k]);
                   }

                   indegree[it]--;
                   if(indegree[it] == 0) q.push(it);

               }
           }
        }
      if(numberOfNodes == n) return ans;
      return -1;
}
};

