class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
            if(nums.size()%k!=0) return 0;

        int n=nums.size();
        // sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        int i=0;
        while(mp.size()>0)
        {
            int curval=mp.begin()->first;
            int curfreq=mp[curval];
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
            if(mp[curval]==0)
            {
                mp.erase(curval);
                // i++;
            }
        }
        
        return true;
    }
};