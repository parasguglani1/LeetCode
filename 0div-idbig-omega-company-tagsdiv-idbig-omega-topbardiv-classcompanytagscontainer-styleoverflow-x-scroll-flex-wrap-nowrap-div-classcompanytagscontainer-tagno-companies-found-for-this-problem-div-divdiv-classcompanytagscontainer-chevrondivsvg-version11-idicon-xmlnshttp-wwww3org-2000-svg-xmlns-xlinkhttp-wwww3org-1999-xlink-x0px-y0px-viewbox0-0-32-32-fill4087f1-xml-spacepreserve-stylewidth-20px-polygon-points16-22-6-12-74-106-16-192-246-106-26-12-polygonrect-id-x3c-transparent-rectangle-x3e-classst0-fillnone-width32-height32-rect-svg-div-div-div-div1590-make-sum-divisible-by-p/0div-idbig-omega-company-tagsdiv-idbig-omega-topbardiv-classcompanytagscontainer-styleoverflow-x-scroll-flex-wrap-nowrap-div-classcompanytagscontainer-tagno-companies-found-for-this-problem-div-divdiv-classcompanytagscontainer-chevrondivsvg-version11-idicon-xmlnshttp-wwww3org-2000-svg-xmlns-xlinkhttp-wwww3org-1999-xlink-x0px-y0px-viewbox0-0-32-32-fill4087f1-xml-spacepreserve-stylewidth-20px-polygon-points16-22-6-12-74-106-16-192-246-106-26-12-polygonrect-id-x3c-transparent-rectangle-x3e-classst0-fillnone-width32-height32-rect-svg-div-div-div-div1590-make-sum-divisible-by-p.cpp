class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sm=accumulate(nums.begin(),nums.end(),0ll);
        
        int mod=sm%p;
        if(mod==0)
        {
            return 0;
        }
        int n=nums.size();
        int ans=n;
        
        map<int,int> mp;
        mp[0]=-1;
         sm=0;
        for(int i=0;i<n;i++)
        {
            
            sm+=nums[i];
            sm%=p;
            int target=(sm-mod+p)%p;
            if(mp.find(target)!=mp.end())
            {
                ans=min(ans,i-mp[target]);
            }
            mp[sm]=i;
            
            
        }
        if(ans==n)
        {
            return -1;
        }
        return ans;
        
        
        
        
    
    }
};