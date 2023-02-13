class Solution
{
    public:
        int reverse(int x)
        {
            bool neg = false;
            if (x < 0)
            {
                neg = true;
            }
            int ans = 0;
            x = abs(x);
            while (x > 0)
            {
                if (ans > INT_MAX / 10)
                {
                    return 0;
                }
                ans *= 10;
                ans += x % 10;

                x /= 10;
                // if (ans < 0)
                // {
                //     return 0;
                // }
            }

            if (neg)
            {
                ans *= -1;
            }
            return ans;
        }
};