class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int neg=0;
        for(int i=0;i<n;i++)
        {
            if(!nums[i])
            {
                return 0;
            }
            if(nums[i]<0)
            {
                neg++;
            }
        }
        if(neg%2)
        {
            return -1;
        }
        return 1;
    }
};