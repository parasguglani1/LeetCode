class Solution {
public:
void detonate(vector<vector<int>>& bombs, vector<bool>& detonated, int i) {
    int n = bombs.size();
    for (int j = 0; j < n; j++) {
        if (detonated[j]) continue;
        long long dx = bombs[i][0] - bombs[j][0];
        long long dy = bombs[i][1] - bombs[j][1];
        long long d2 = dx * dx + dy * dy;
        long long r2 = (long long)bombs[i][2] * bombs[i][2];
        if (d2 <= r2) {
            detonated[j] = true;
            detonate(bombs, detonated, j);
        }
    }
}

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    int res = 1;
    for (int i = 0; i < n; i++) {
        vector<bool> detonated(n);
        detonated[i] = true;
        detonate(bombs, detonated, i);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (detonated[j]) cnt++;
        }
        res = max(res, cnt);
    }
    return res;
}    
};
