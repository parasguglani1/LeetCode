class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &arr)
        {
           	// support variables
            int lmtLeft = 0, lmtRight = arr[0].size(), lmtUp = 0, lmtDown = arr.size(), i = 0, tot = lmtRight-- *lmtDown--;
            vector<int> res(tot);
            while (true)
            {
               	// going right
                for (int x = lmtLeft, y = lmtUp++; x <= lmtRight; x++) res[i++] = arr[y][x];
                if (i == tot) break;
               	// going down
                for (int y = lmtUp, x = lmtRight--; y <= lmtDown; y++) res[i++] = arr[y][x];
                if (i == tot) break;
               	// going left
                for (int x = lmtRight, y = lmtDown--; x >= lmtLeft; x--) res[i++] = arr[y][x];
                if (i == tot) break;
               	// going up
                for (int y = lmtDown, x = lmtLeft++; y >= lmtUp; y--) res[i++] = arr[y][x];
                if (i == tot) break;
            }
            return res;
        }
};