class Solution {
public:
    int minFlipsMonoIncr(string s) {
                int n = s.size();
        int one_counts = 0;
        int steps = 0;
        
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == '1') {
                one_counts++;
            } else {
                steps = min(steps + 1, one_counts);
            }
        }
        
        return steps;

    }
};