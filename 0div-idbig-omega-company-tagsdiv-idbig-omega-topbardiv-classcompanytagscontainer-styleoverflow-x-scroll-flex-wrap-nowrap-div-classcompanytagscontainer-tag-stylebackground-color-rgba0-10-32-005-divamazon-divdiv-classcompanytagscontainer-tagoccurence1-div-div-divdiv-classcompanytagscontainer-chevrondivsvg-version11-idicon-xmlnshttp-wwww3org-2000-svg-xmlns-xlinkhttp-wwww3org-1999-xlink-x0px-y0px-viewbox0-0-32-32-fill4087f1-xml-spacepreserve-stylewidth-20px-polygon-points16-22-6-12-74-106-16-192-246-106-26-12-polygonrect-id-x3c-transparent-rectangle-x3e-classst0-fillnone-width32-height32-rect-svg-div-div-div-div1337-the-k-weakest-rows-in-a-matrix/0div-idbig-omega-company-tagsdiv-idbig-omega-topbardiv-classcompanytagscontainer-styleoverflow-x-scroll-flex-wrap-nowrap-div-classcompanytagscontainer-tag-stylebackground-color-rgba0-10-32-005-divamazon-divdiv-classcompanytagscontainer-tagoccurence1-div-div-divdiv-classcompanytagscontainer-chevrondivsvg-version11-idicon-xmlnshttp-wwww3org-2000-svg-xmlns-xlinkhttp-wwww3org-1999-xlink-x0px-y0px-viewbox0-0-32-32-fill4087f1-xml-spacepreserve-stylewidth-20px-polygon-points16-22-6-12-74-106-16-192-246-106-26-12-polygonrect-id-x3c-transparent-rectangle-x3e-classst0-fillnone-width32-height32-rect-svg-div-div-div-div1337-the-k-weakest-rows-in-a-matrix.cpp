class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
     int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
          // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int,int>>v;
        // priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            cnt=0;
            for(int j=0;j<m;j++)
            {
                cnt+=mat[i][j];
            }
            v.push_back({cnt,i}); 
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
        // cout<<v[i].first<<' ';
        }
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
            // auto t=pq.top();
            // ans.push_back(t.second);
            // pq.pop();
        }
        return ans;
    }
};