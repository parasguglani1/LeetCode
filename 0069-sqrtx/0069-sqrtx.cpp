class Solution
{
    public:
        int mySqrt(int x)
        {
            long long l = 1, r = (long)x +1;
            while (l < r)
            {
                long long mid = l + (r - l) / 2;
                if (mid  <= x/mid)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            return l - 1;
        }
};