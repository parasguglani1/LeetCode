class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(auto x:points)
        {
            int distance=x[0]*x[0]+x[1]*x[1];
            pq.push({distance,x});
            if(pq.size()>k)
            {
                pq.pop();
            }
            
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};