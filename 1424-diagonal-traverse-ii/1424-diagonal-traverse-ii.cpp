class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        
        map<int,vector<int>> mp;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto &x:mp)
        {
            auto &v=x.second;
            reverse(v.begin(),v.end());
            ans.insert(ans.end(),v.begin(),v.end());
            
        }
        return ans;
        
        
    }
};
