class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int prev=nums[0],prev2=0;
        int take=0,nottake=0,curr=0;
        for(int i=1;i<n;i++)
        {
            
            take=nums[i]+prev2;
            nottake=prev;
            
            curr=max(take,nottake);
            prev2=prev;
            prev=curr;
            
        }
        return curr;
    }
};