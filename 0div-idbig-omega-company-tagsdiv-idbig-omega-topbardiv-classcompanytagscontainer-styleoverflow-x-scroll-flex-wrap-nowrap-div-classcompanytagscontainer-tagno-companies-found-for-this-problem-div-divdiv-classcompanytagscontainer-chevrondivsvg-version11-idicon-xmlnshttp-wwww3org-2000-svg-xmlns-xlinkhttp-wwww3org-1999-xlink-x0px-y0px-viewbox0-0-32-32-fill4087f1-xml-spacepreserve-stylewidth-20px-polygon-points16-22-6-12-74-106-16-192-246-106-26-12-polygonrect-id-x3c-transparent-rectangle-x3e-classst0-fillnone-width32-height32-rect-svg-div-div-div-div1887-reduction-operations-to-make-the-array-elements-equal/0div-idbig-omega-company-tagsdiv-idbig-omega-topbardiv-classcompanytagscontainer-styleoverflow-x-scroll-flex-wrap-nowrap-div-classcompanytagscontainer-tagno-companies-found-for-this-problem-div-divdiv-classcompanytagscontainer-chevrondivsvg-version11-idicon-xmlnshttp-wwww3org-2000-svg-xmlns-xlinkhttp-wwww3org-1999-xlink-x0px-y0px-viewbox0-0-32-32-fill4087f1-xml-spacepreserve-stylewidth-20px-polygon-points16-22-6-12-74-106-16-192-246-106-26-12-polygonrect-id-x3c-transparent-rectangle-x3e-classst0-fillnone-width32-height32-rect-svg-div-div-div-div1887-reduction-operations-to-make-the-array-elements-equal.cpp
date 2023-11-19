class Solution {
public:
    int reductionOperations(vector<int>& nums) {
     // 1 1 2 2 3 3
         sort(nums.begin(),nums.end());
        int rank=0;
    int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                rank++;
            ans+=rank;
        }
        return ans;

    }
};