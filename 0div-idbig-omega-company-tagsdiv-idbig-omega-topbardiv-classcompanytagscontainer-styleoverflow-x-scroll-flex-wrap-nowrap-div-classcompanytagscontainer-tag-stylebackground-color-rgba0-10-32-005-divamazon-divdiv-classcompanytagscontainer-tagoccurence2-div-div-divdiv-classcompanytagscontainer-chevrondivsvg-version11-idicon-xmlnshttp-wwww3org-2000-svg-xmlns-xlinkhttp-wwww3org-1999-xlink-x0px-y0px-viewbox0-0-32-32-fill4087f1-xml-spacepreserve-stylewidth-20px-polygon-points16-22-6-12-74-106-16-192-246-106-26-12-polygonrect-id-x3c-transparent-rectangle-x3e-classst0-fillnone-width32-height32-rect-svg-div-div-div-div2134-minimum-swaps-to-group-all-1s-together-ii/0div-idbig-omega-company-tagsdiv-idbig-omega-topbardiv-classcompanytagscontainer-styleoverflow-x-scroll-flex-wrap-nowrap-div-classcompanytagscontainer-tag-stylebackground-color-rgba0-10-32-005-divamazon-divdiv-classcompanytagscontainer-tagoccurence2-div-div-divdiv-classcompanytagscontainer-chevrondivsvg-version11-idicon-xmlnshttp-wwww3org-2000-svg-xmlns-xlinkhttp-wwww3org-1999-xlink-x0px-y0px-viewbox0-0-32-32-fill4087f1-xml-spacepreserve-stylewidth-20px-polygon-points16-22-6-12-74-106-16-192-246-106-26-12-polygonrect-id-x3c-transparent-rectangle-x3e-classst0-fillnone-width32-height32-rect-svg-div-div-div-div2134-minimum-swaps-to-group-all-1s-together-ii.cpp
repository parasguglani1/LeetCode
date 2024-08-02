class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        for(auto x:nums)
        {
            if(x)
            {
                cnt1++;
            }
        }
        int k=cnt1;
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
            
        }
        
        int ans=INT_MAX;
        int cnt=0;
        for(int i=0;i<k;i++)
        {
            if(nums[i])
            {
                cnt++;
            }
        }
        ans=min(ans,k-cnt);
        
        for(int i=k;i<2*n;i++)
        {
            if(nums[i])
            {
                cnt++;
            }
            if(nums[i-k])
            {
                cnt--;
            }
            ans=min(ans,k-cnt);
        }
        return ans;
    }
};