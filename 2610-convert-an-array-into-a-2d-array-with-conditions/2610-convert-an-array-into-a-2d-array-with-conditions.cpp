class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        int mx=0;
        for(auto &x:nums)
        {
            mp[x]++;
            mx=max(mx,mp[x]);
        }
        
        vector<vector<int>> ans(mx,vector<int>());
        
        for(auto &x:mp)
        {
            
            auto &ele=x.first;
            auto &freq=x.second;
            
            for(int i=0;i<freq;i++)
            {
                ans[i].emplace_back(ele);
            }
        }
        return ans;
        
    }
};