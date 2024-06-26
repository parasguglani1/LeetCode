class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        vector<int> ans;
        for(auto x:s1)
        {
            if(s2.find(x)!=s2.end())
            {
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};