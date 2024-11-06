class Solution {
public:
   bool canSortArray(vector<int>& nums) {

        int n = nums.size() , i = 0 , j = 0 , prevMax = 0;
        while(i < n) {

            int currMax = 0 , currMin = 257 , cnt = __builtin_popcount(nums[i]);
            while(j < n && cnt == __builtin_popcount(nums[j])) {
                currMax = max(currMax,nums[j]);
                currMin = min(currMin,nums[j]);
                j++;
            }

            if(currMin > prevMax) prevMax = currMax;
            else return false;

            i = j;
        }
        return true;
    }
};