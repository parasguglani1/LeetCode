class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        int ans=0;
        
        for(auto x:mp)
        {
            if(x.second==1)
            {
                return -1;
            }
         
                ans+=ceil((float)x.second/3);
         
        }
        return ans;
       
    }
};