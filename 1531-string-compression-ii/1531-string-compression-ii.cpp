class Solution {
public:
    // time/space: O(nnk)/O(nk)
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k + 1, INT_MAX));
        return helper(s, 0, k, dp);
    }
private:
    int helper(string& s, int i, int k, vector<vector<int>>& dp) {
        // terminate
        if (k < 0) return INT_MAX;
        if (i >= s.size()) return 0;
        if ((s.size() - i) <= k) return 0;
        if (dp[i][k] != INT_MAX) return dp[i][k];

        // enumerate
        int min_len = INT_MAX;
        int max_freq = 0;
        unordered_map<char, int> freq;
        for (int j = i; j < s.size(); j++) {
            // find the maximum frequency in `s[i..j]`
            max_freq = max(max_freq, ++freq[s[j]]);
            // keep the character with the maximum frequency, and remove the other characters
            int encoded_len = getDigits(max_freq);
            int delete_count = (j - i + 1) - max_freq;
            // find the encoded lenght of the next sub-string `s[(j + 1):]`
            int next_length = helper(s, j + 1, k - delete_count, dp);
            if (next_length == INT_MAX) continue;
            // update the optimal encoded length of `s[i:]`
            min_len = min(min_len, encoded_len + next_length);
        }
        return dp[i][k] = min_len;
    }
    int getDigits(int x) {
        if (x <= 1) return x;
        if (x < 10) return 2;
        if (x < 100) return 3;
        return 4;
    }
};
