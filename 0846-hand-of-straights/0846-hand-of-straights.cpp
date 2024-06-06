class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
                int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        int i=0;
        while(mp.size()>0)
        {
            int curval=mp.begin()->first;
            int curfreq=mp[nums[i]];
            for(int j=curval;j<curval+k;j++)
            {
                if(mp[j]<curfreq)
                {
                    return false;
                }
                mp[j]-=curfreq;    
                if(mp[j]==0)
                {
                mp.erase(j);
                }
            }
            if(mp[nums[i]]==0)
            {
                mp.erase(nums[i]);
                i++;
            }
        }
        
        return true;
    }
};