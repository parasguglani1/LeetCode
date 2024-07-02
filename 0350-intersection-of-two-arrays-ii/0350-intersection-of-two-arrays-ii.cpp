class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1,mp2;
        for(auto x:nums1) mp1[x]++;
        for(auto x:nums2) mp2[x]++;
        
        vector<int> ans;
        for(auto x:mp1)
        {
            int freq=min(x.second,mp2[x.first]);
            while(freq--) ans.push_back(x.first);
        }
        return ans;

    }
};