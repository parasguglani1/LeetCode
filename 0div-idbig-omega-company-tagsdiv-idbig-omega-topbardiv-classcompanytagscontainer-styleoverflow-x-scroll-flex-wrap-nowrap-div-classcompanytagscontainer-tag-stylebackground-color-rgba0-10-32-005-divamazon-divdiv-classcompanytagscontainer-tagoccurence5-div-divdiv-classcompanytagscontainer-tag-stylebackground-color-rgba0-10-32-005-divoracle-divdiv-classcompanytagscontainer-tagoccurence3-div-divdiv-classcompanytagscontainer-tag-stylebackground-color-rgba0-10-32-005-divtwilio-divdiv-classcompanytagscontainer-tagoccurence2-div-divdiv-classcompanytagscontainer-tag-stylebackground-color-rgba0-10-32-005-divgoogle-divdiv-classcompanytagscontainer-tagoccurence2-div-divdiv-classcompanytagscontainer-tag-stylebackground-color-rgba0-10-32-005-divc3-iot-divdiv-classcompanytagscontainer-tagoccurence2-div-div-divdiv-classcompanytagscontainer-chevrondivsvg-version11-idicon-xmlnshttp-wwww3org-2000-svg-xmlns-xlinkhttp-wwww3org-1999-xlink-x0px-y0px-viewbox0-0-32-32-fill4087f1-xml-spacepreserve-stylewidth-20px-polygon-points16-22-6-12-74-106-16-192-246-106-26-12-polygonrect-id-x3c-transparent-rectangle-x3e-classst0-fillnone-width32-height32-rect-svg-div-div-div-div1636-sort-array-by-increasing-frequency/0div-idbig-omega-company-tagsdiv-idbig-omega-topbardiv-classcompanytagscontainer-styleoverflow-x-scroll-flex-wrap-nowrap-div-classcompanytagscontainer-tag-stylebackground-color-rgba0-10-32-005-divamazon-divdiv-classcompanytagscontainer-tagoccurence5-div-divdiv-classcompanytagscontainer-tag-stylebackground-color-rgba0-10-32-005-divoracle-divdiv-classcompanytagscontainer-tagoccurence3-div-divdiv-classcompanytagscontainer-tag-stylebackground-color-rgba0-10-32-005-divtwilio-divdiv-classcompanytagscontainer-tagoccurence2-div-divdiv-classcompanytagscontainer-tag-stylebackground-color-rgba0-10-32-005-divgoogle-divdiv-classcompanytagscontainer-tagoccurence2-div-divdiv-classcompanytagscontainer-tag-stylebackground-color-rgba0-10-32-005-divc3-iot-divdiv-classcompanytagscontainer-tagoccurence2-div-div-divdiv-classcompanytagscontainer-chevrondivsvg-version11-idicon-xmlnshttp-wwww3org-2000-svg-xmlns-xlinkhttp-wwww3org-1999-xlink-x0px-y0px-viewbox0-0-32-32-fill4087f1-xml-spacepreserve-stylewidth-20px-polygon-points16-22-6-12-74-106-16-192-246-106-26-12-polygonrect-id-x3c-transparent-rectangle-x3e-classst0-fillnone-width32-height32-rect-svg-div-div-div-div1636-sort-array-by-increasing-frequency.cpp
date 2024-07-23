class Solution {
public:
   static bool cmp(pair<int,int> a ,pair<int,int> b)
    {
        if(a.first==b.first)
        {
            return a.second> b.second;
        }
        return a<b;
    }
    vector<int> frequencySort(vector<int>& nums) {
       int n=nums.size();
        
        map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        vector<pair<int,int>> vp;
        for(auto x:mp)
        {
            vp.push_back({x.second,x.first});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<int> ans;
        
        for(int i=0;i<vp.size();i++)
        {
            for(int j=0;j<vp[i].first;j++)
            {
                ans.push_back(vp[i].second);
            }
        }
        return ans;
        
    }
};