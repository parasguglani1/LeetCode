class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int n = arr.size();
            vector<int> v(2001, 0);
            for (int i = 0; i < n; i++)
            {
                v[arr[i]]++;
            }
            for (int i = 1; i < 2001; i++)
            {

                if (v[i] == 0)
                {
                    k--;
                }
                if (k == 0)
                {
                    return i;
                }
            }
            return 2001;
        }
};