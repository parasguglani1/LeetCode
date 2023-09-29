class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool isinc=true,isdec=true;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                isdec=false;
            }
            else if(nums[i]==nums[i+1])
            {
                
            }
            else
            {
                isinc=false;
            }
        }
        return isdec ||isinc;
    }
};