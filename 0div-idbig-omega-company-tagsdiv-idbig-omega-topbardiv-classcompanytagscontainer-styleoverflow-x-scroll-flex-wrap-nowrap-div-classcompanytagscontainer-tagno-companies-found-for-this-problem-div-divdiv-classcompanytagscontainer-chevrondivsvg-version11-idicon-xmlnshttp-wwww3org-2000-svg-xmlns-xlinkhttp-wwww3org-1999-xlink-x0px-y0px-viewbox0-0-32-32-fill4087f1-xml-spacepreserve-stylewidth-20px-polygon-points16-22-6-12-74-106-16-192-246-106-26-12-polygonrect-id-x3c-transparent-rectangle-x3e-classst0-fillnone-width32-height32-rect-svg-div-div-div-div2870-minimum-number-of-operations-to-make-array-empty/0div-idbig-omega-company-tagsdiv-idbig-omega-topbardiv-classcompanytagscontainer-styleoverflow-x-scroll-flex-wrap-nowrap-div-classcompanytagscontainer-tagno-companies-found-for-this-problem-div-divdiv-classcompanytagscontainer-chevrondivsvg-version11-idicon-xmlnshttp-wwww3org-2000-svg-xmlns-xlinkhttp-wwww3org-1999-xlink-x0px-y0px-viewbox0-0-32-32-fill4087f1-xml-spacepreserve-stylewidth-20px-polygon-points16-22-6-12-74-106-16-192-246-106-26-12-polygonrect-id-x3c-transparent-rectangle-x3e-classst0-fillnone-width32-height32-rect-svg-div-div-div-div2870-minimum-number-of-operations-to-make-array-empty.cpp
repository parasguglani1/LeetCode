class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto &x:nums)
        {
            mp[x]++;
        }
        int ans=0;
        
        for(auto &[x,y]:mp)
        {
            if(y==1)
            {
                return -1;
            }
         
                ans+=ceil((float)y/3);
         
        }
        return ans;
       
    }
};