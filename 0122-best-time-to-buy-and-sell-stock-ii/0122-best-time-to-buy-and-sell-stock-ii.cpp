class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> next(2, 0), curr(2, 0);
        for(int idx = n-1; idx >= 0; idx--){

            int b = -p[idx] + next[0];

            int nb = 0 + next[1];

            int s = p[idx] + next[1];

            int ns = 0 + next[0];

            curr[0] = max(s, ns);

            curr[1] = max(b, nb);
            
            next = curr;
        }
        return curr[1];
    }
};
