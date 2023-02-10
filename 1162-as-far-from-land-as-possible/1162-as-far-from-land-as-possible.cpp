class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>>  q;
        int n = grid.size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1)
                    q.push({i, j});
            }
        }
        vector<int> dir{0, 1, 0, -1, 0};
        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [r, c] = q.front();
                q.pop();
                
                for(int i=0;i<4;i++) {
                    int nr = r+dir[i];
                    int nc = c+dir[i+1];
                    
                    if(min(nr, nc) <0 || max(nr, nc)==n || grid[nr][nc]!=0)
                        continue;
                    grid[nr][nc] = grid[r][c] +1;
                    q.push({nr, nc});
					ans = max(ans, grid[nr][nc]);
                }
            }
        }
        return ans-1;
    }

};