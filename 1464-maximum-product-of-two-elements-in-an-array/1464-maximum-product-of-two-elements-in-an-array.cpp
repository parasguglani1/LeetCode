class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxind=max_element(nums.begin(),nums.end())-nums.begin();
        int max1=nums[mxind];
        int max2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=mxind)
            {
                max2=max(max2,nums[i]);
            }
        }
        return (max1-1)*(max2-1);
        
    }
};