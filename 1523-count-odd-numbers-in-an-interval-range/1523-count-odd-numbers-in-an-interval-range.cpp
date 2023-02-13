class Solution {
public:
    int countOdds(int low, int high) {
        return ceil((high-low)/2.0)+(high%2 && low%2);
    }
};