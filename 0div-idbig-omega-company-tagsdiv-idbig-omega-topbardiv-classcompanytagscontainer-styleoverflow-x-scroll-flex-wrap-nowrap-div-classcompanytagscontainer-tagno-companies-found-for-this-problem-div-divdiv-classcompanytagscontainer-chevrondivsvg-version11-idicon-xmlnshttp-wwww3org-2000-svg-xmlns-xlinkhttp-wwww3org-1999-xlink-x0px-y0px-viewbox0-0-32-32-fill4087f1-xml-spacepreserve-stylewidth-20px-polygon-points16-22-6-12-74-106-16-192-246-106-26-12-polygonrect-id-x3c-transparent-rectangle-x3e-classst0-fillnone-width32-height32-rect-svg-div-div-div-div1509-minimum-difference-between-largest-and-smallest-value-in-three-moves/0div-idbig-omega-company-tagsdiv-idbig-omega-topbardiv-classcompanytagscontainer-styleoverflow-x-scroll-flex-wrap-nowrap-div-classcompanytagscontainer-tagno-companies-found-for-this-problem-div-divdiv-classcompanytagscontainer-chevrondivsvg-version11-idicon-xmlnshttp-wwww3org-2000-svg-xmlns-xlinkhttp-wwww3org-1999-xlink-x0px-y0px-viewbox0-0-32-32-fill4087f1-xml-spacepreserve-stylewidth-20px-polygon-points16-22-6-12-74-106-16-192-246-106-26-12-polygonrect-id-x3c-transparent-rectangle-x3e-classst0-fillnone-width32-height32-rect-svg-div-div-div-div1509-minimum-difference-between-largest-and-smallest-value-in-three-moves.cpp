class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();


        if(n<5)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        // 4 and last
        int ans=nums[n-1]-nums[3];
        int ans2=nums[n-2]-nums[2];
        int ans3=nums[n-3]-nums[1];
        int ans4=nums[n-4]-nums[0];
        
        return min({ans,ans2,ans3,ans4});
    }
};


// 1  4 4 5 9 