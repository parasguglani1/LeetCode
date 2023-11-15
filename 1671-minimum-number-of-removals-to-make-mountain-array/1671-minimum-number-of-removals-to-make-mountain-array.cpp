class Solution
{
    public:
        int minimumMountainRemovals(vector<int> &arr)
        {
            int n = arr.size();
            vector<int> incdp(n, 1), decdp(n, 1);
            int mx = 1;
           	// incdp[0] = 1, decdp[n - 1] = 1;
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (arr[j] < arr[i])
                    {
                        incdp[i] = max(incdp[i], incdp[j] + 1);
                    }
                }
            }

            for (int i = n - 2; i >= 0; i--)
            {
                for (int j = n - 1; j > i; j--)
                {
                    if (arr[j] < arr[i])
                    {
                        decdp[i] = max(decdp[i], decdp[j] + 1);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (incdp[i] != 1 && decdp[i] != 1)
                {
                    mx = max(incdp[i] + decdp[i] - 1, mx);
                }
            }
            return n - mx;
        }
};