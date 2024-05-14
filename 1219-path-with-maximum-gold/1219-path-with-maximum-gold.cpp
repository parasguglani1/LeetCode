class Solution
{
    public:

        bool isValid(int x, int y, vector<vector < int>> &grid)
        {
            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
            {
                return false;
            }
            return true;
        }

    int visit(int x, int y, vector<vector < int>> &grid)
    {
        vector<int> dx = { -1,
            0,
            1,
            0
        };
        vector<int> dy = { 0,
            -1,
            0,
            1
        };

        int cur = grid[x][y];
        grid[x][y] = 0;
        int curmax = cur;
        for (int i = 0; i < 4; i++)
        {
            int newx = dx[i] + x;
            int newy = dy[i] + y;
            if (isValid(newx, newy, grid))
            {
                curmax = max(curmax, cur+visit(newx, newy, grid));
            }
        }
        grid[x][y] = cur;
        return curmax;
    }
    int getMaximumGold(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cursum = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)

                    {
                        cursum = visit(i, j, grid);
                        ans = max(ans, cursum);
                    }
                }
            }
            return ans;
        }
    };