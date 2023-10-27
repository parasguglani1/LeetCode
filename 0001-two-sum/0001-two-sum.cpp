class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i+1;
        }
        for(int i=0;i<n;i++)
        {
            int fnd=target-nums[i];
            if(mp[fnd]>0 && mp[fnd]!=i+1)
            {
                return{ mp[fnd]-1,i};
            }
        }
        return {};
    }
};