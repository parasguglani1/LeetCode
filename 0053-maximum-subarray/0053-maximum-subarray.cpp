class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxm=INT_MIN;
        int currsum=0;
        int maxelement=INT_MIN;
        if(nums.size()==1)
        {
            return nums[0];
        }
        for(int i=0;i<nums.size();i++)
        {
            maxelement=max(maxelement,nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            if(currsum<0)
            {
                currsum=0;
            }
            maxm=max(maxm,currsum);
            
        }
        
        if(maxm==0)
        {
            return maxelement;
        }
        return maxm;
    }
};