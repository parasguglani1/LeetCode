class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=__builtin_popcount(n);
        return ans;
    }
};