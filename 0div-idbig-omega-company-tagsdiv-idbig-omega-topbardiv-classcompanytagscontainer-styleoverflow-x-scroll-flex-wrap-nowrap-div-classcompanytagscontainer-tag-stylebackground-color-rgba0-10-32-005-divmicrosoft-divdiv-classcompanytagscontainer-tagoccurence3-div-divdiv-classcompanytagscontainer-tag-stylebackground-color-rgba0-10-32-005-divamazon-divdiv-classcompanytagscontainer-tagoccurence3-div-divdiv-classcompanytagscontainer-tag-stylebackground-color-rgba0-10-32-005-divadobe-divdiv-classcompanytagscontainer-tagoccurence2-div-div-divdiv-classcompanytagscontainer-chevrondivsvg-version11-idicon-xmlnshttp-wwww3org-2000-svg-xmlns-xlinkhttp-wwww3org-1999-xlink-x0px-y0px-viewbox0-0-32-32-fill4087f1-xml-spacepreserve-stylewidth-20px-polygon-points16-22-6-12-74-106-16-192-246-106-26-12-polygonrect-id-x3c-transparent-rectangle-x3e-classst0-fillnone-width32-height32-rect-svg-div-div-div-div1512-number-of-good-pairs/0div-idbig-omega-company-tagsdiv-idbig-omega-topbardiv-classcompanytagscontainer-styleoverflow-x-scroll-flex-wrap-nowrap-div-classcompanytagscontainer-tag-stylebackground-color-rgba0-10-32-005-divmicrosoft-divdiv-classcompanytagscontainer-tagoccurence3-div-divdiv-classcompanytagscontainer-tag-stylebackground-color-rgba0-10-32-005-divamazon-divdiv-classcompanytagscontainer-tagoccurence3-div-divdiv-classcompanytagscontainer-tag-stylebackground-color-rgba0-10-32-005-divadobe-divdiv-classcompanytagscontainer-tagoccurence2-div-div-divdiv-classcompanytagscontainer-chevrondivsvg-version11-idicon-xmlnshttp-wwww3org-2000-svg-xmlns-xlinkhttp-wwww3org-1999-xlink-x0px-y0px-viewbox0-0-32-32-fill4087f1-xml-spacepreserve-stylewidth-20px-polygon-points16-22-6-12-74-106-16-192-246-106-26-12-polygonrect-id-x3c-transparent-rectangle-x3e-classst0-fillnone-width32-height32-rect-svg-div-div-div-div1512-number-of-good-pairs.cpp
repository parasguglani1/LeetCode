class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int cnt=0;
        for(auto x:nums){mp[x]++; cnt+=mp[x]-1;}
        // for(auto x:nums);
        return cnt;
      
            
    }
};