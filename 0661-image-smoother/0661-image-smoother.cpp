class Solution
{
    public:
        int n, m;
    bool isValid(int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return false;
        }
        return true;
    }

    vector<vector < int>> imageSmoother(vector<vector < int>> &img)
    {
        int nn = img.size();
        int mm = img[0].size();
        n = nn, m = mm;

        vector<vector < int>> res(n, vector<int> (m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0, ans = 0;
                for (int k = -1; k < 2; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        int newx = i + k;
                        int newy = j + l;
                        if (isValid(newx, newy))
                        {
                            ans += img[newx][newy];
                            cnt++;
                        }
                    }
                }
                res[i][j] = ans / cnt;
                                // ans[i][j] = 1;
            }
        }

        return res;
    }
};