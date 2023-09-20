class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> pref(n+1),suff(n+1);
        pref[0]=nums[0];
        map<int,int> pmp,smp;
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
            pmp.insert({pref[i],i+1});
        }
        pmp.insert({pref[0],1});
        suff[n-1]=nums[n-1];
        smp.insert({suff[n-1],1});
        
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+nums[i];
            smp.insert({suff[i],n-i});
        }
        int ans=INT_MAX;
        for(auto c:pmp)
        {
            if(c.first==x)
            {
                ans=min(ans,c.second);
            }
        }
        cout<<ans<<endl;
        for(auto c:smp)
        {
            if(c.first==x)
            {
                ans=min(ans,c.second);
            }
        }
        // cout<<ans<<endl;
        
        for(auto c:pmp)
        {
            int fnd=x-c.first;
//             modify this line
            if(smp[fnd] &&c.second+smp[fnd]<n)
            {
                ans=min(ans,smp[fnd]+c.second);
            }
        }
        // cout<<ans<<endl;
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
        
        
        
    }
};