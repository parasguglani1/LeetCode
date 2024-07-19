class Solution
{
    public:
        vector<int> luckyNumbers(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int curr = matrix[i][j];
                    bool isMax = true, isMin = true;;
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[k][j] > curr)
                        {
                            isMax = false;
                        }
                    }
                    for (int k = 0; k <m; k++)
                    {
                        if (matrix[i][k] < curr)
                        {
                            isMin = false;
                        }
                    }
                    if (isMax && isMin)
                    {
                        ans.push_back(curr);
                    }
                }
            }
            return ans;
        }
};