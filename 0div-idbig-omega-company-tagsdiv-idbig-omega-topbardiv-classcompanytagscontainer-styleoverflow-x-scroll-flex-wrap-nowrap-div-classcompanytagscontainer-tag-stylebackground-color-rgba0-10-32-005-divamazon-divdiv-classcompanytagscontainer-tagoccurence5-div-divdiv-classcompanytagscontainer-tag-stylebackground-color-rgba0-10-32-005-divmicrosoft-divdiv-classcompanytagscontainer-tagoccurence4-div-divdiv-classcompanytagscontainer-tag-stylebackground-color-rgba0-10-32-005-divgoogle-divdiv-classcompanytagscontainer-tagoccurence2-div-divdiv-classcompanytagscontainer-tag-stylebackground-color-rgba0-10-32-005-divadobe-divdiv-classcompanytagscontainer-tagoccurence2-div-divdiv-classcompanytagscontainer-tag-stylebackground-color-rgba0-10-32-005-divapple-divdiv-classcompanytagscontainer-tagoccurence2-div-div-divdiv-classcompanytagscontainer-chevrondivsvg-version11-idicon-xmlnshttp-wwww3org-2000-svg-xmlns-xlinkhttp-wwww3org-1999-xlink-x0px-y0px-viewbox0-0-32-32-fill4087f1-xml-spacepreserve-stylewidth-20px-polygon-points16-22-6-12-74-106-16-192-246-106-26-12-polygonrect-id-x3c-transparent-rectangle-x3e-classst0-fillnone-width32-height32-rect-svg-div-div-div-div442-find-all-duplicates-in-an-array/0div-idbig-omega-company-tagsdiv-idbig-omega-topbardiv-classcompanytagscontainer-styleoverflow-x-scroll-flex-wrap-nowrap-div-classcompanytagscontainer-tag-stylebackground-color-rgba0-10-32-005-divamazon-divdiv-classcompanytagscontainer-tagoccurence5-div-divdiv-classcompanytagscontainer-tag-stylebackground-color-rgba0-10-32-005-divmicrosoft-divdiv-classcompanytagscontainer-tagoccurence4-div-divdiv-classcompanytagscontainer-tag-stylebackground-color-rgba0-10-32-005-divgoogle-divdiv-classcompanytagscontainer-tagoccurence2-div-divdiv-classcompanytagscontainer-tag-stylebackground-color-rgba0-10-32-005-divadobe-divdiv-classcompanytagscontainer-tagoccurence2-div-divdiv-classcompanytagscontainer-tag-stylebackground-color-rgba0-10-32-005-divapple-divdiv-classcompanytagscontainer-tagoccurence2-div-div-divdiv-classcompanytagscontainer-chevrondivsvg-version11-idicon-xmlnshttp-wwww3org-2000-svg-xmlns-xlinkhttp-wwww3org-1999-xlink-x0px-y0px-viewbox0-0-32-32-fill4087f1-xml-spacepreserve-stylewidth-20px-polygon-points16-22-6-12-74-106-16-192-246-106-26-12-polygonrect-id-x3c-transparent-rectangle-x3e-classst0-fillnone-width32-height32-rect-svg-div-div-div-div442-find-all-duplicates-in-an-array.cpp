class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int x = abs(nums[i]) - 1;
            if(nums[x] < 0) ans.push_back(x+1);
            else {
                nums[x] *= -1;
            }
        }
        return ans;
    }
};
