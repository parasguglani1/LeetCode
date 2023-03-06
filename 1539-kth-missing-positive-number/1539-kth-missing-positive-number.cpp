class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int n = arr.size();
            int l = 0, r = n ;
            if(arr[0]>k)
            {
                return k;
            }
            while (l < r)
            {
                int mid = (l + r) / 2;
                int miss = arr[mid] - mid - 1;
                // if (miss == k)
                // {
                //     return arr[mid];
                // }
                 if (miss < k)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid ;
                }
            }
            return r+k;
        }
};