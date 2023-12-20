class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(i+k-1<n)
            {
                ans=min(ans,nums[i+k-1]-nums[i]);
            }
        }
        return ans;

    }
};