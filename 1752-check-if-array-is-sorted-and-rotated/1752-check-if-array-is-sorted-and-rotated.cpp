class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        nums.push_back(nums[0]);
        for(int i=0;i<n;i++)
        {
            if(nums[i+1]<nums[i])
                     cnt++;
        }
        return cnt<2;
    }
};