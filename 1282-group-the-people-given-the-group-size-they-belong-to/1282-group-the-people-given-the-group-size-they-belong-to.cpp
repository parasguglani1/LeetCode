class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        map<int,vector<int>> mp;
        int n=v.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            mp[v[i]].push_back(i);
        }
        for(auto x: mp)
        {
            vector<int> vs=x.second;
            int sz=x.second.size();
            int vecs=sz/x.first;
            // int j=0;
            for(int i=0;i<sz;i)
            {
                vector<int> temp;
                for(int j=0;j<x.first;j++)
                {
                    temp.push_back(vs[i++]);
                }
                ans.push_back(temp);
                
            }
        }
        return ans;
    }
};