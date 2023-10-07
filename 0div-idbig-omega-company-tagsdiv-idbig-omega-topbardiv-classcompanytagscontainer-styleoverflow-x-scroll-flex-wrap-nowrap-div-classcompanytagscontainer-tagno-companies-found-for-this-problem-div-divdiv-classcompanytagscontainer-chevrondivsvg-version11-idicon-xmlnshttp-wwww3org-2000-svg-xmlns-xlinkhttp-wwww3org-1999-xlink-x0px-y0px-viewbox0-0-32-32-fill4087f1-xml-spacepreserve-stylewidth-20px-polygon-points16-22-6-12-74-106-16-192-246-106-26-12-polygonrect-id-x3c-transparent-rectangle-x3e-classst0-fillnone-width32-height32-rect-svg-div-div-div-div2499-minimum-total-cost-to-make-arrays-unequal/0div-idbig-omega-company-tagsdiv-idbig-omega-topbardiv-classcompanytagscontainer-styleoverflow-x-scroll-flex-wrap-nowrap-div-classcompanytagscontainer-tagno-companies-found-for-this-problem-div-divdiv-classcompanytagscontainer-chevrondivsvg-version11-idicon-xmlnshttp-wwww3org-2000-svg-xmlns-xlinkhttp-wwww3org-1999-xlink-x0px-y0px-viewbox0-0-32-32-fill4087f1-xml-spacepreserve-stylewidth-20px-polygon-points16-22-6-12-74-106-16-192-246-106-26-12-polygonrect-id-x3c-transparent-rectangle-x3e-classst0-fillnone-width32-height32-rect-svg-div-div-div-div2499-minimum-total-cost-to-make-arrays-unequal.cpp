class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), total = 0;
        long long ans = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i)
            if(nums1[i] == nums2[i]) {
                ++freq[nums1[i]];
                ++total; 
                ans += i;
            }
        if (!total) return 0; 
        auto [key, most] = *max_element(freq.begin(), freq.end(), [&](auto& lhs, auto& rhs) {return lhs.second < rhs.second;}); 
        for (int i = 0; i < n && 2*most > total; ++i) 
            if (nums1[i] != nums2[i] && key != nums1[i] && key != nums2[i]) {
                ++total;
                ans += i;
            }
        return 2*most > total ? -1 : ans; 
    }
};
