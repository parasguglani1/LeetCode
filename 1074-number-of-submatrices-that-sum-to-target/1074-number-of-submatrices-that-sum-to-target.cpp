class Solution
{
    public:
        int numSubmatrixSumTarget(vector<vector < int>> &matrix, int target)
        {
            long long prefix[101][101];
            int m = matrix.size(), n = matrix[0].size();

            for (int i = 0; i <= n; i++)
                prefix[0][i] = 0;
            for (int i = 0; i <= m; i++)
                prefix[i][0] = 0;

           	//1D prefix sum in each row
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                    prefix[i][j] = prefix[i][j - 1] + matrix[i - 1][j - 1];
            }

           	//2D prefix sum in each row, store the answer in the right-bottom corner
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                    prefix[i][j] += prefix[i - 1][j];
            }

            int ans = 0;

           	//find all possible rectangle
           	//(i,j) : left-top corner
           	//(x,y) : right-bottom corner
            for (int x = 1; x <= m; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    for (int i = 1; i <= x; i++)
                    {
                        for (int j = 1; j <= y; j++)
                        {
                           	//sum of the rectagle
                            long long sum = prefix[x][y] - prefix[x][j - 1] - prefix[i - 1][y] + prefix[i - 1][j - 1];
                            if (sum == target) ans++;
                        }
                    }
                }
            }
            return ans;
        }
};