class Solution
{
    public:

        int getdp(int n, vector<int> &dp, int &mx)
        {
            if (n < 2)
            {
                mx = max(mx, n);
                return n;
            }
            if (n % 2 == 0)
            {

                int curr = getdp(n / 2, dp, mx);
                mx = max(curr, mx);
                return curr;
            }
            else
            {
                int curr = getdp(n / 2, dp, mx) + getdp(n / 2 + 1, dp, mx);
                mx = max(curr, mx);
                return curr;
            }
        }

    int getMaximumGenerated(int n)
    {
       	//         nums[10]=nums[5];
       	//         nums[12]=nums[6];

       	//         nums[6]=nums[3];
       	//         nums[3]=nums[1]+nums[2];
       	//         nums[5]=nums[2]+nums[3];

       	//         vector<int> dp(n+1);
        vector<int> dp(n + 1);
if(n<2)
{
    return n;
}
        dp[0] = 0;
        dp[1] = 1;

        int mx = INT_MIN;

        for (int i = 2; i <= n; i++)
        {
            if (i % 2)
            {
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
                mx = max(mx, dp[i]);
            }
            else
            {
                dp[i] = dp[i / 2];
                mx = max(mx, dp[i]);
            }
        }

        return mx;
    }
};