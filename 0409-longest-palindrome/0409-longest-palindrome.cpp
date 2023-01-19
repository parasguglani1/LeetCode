class Solution {
public:
    int longestPalindrome(string s) {
     bitset<64> bits(0);
    for (char c : s) bits.flip(c - 'A');
    return s.size() - bits.count() + bits.any();

        
    }
};