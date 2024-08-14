class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lb = 0;
        int rb = nums[n-1] - nums[0];
        
        while (lb <= rb) {
            int mid = lb + (rb - lb) / 2;
            int pairCount = 0;
            int i = 0;
            
            for (int j = 0; j < n; ++j) {
                while (nums[j] - nums[i] > mid) {
                    i++;
                }
                pairCount += (j - i);
            }
            
            if (pairCount < k) {
                lb = mid + 1;
            } else {
                rb = mid - 1;
            }
        }
        
        return lb;
    }
};
