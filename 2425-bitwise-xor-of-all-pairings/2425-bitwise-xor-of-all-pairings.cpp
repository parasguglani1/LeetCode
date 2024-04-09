class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;

        if(n%2)
        {
            for(auto &x:nums2)
            {
                ans^=x;
            }
        }
        if(m%2)
        {
            for(auto &x:nums1)
            {
                ans^=x;
            }
        }
        return ans;
    }
};