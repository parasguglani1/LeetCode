class Solution
{
    public:
        int maxCount(int m, int n, vector<vector < int>> &ops)
        {
            int mnx = INT_MAX;
            int mny = INT_MAX;
            int sz = ops.size();
            if(sz==0)
            {
                return m*n;
            }
            for (int i = 0; i < sz; i++)
            {
                mnx = min(mnx, ops[i][0]);
                mny = min(mny, ops[i][1]);
            }
            return mnx*mny;
    
        }
};