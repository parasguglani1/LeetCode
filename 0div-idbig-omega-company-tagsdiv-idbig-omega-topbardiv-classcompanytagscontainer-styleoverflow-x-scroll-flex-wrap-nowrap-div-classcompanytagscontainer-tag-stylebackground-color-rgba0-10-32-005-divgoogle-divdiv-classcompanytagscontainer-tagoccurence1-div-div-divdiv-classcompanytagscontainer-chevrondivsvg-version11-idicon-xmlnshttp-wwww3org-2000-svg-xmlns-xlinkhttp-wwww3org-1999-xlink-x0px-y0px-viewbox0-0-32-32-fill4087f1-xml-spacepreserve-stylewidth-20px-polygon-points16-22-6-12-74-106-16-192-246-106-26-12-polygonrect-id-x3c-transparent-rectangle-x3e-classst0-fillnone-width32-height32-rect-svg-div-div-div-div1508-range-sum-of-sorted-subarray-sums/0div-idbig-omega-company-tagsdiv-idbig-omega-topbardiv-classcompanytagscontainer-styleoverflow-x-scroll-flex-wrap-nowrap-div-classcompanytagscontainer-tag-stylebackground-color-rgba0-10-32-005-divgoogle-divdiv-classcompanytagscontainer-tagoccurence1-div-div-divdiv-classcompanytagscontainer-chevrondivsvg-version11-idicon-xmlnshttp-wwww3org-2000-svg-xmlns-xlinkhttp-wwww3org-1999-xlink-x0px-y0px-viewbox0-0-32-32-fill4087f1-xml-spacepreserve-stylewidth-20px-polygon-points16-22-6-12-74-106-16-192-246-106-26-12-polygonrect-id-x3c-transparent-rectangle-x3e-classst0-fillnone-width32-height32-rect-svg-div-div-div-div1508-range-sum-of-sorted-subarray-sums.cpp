class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1000000007;
        
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                minHeap.push(prefix[i] - prefix[j]);
            }
        }
        
        long long result = 0;
        for (int i = 1; i <= right; ++i) {
            int sum_value = minHeap.top();
            minHeap.pop();
            if (i >= left) {
                result = (result + sum_value) % MOD;
            }
        }
        
        return result;
    }
};
