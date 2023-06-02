class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n-1 == 0 && grid[0][0] == 0)
            return 1;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue <pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        int drow[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dcol[] = {0, +1, +1, +1, 0, -1, -1, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                    if (dist[row][col] + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dist[row][col] + 1;
                        if (nrow == n-1 && ncol == n-1)
                            return dist[n-1][n-1];
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};
